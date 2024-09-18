#include "Chara_Player.h"
#include "../../StageObject/Attack/Bullet.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"  
#include "../../Engine/SphereCollider.h"
#include "../../StageObject/Score/Score.h"
#include "../../Engine/SceneManager.h"
#include "../../Scene/Scene_Title.h"
Chara_Player::Chara_Player(GameObject* parent)
    : GameObject(parent, "Chara_Player"), chara_Pict_(-1), chara_speed_(0.01f), chara_width_(64.f), chara_height_(64.f)
    , screenWidth_(1280.f), screenHeight_(720.f),maxScreenX(64.47f), maxScreenY(65.f),minScreen(-0.97f), fireInterval_(0.15f)
    ,player_Hp(2),isInvincible_(false),invincibleDuration_(2.0f)
{
    // コンストラクタで最後の発射時間を現在時間に設定
    lastFireTime_ = std::chrono::steady_clock::now();
}

Chara_Player::~Chara_Player()
{
    
}

void Chara_Player::Initialize()
{
    // 画像データのロード
    chara_Pict_ = Image::Load("Character/Player_Back.png");
    assert(chara_Pict_ >= 0);
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.00005f);
    AddCollider(collision);

    transform_.position_ = { -0.25f,-0.85f,0.0f };
}

void Chara_Player::Update()
{
    // 無敵状態を監視し、時間が経過したら無敵を解除
    if (isInvincible_)
    {
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> elapsedTime = currentTime - invincibleStartTime_;

        if (elapsedTime.count() >= invincibleDuration_)
        {
            isInvincible_ = false;
            Image::SetAlpha(chara_Pict_, 255); // 無敵解除時に透明度を元に戻す
        }
    }
    Move();  // 移動処理を呼び出す
    Shot();
    
}

void Chara_Player::Draw()
{
    if (isInvincible_)
    {
        // 無敵中はキャラクターの透明度を50%にする
        Image::SetAlpha(chara_Pict_, 128);
    }
    else
    {
        // 通常状態
        Image::SetAlpha(chara_Pict_, 255);
    }

    Image::SetTransform(chara_Pict_, transform_);
    Image::Draw(chara_Pict_);
}

void Chara_Player::Release()
{
   
}

void Chara_Player::Move()
{
    // 上に移動
    if (Input::IsKey(DIK_W))
    {
        transform_.position_.y += chara_speed_;
    }
    // 下に移動
    if (Input::IsKey(DIK_S))
    {
        transform_.position_.y -= chara_speed_;
    }
    // 左に移動
    if (Input::IsKey(DIK_A))
    {
        transform_.position_.x -= chara_speed_;
    }
    // 右に移動
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += chara_speed_;
    }
    
    // スクリーンの端に当たるまで
    transform_.position_.x = (transform_.position_.x < -chara_width_ / 2.0f) ? screenWidth_ + chara_width_ / 2.0f :
        (transform_.position_.x > screenWidth_ + chara_width_ / 2.0f) ? -chara_width_ / 2.0f :
        transform_.position_.x;

    transform_.position_.y = (transform_.position_.y < -chara_height_ / 2.0f) ? screenHeight_ + chara_height_ / 2.0f :
        (transform_.position_.y > screenHeight_ + chara_height_ / 2.0f) ? -chara_height_ / 2.0f :
        transform_.position_.y;

    // スクリーンの端に行かないように制限をかける
    transform_.position_.x = max(minScreen, min(transform_.position_.x, maxScreenX - chara_width_));
    transform_.position_.y = max(minScreen, min(transform_.position_.y, maxScreenY - chara_height_));
}



void Chara_Player::Shot()
{
    // 現在の時間を取得
    auto currentTime = std::chrono::steady_clock::now();

    // 前回の発射時間からの経過時間を計算
    std::chrono::duration<float> elapsedTime = currentTime - lastFireTime_;

    if (Scene_Title::IsAutoFireEnabled())
    {
        // 手動発射モード（スペースキーで発射）
        if (Input::IsKeyDown(DIK_SPACE))
        {
            Bullet* pBullet = Instantiate<Bullet>(GetParent());
            pBullet->SetPosition(transform_.position_);
        }
    }
    else
    {
       
        // 自動発射モードの場合、0.5秒ごとに弾を発射
        if (elapsedTime.count() >= fireInterval_)
        {
            Bullet* pBullet = Instantiate<Bullet>(GetParent());
            pBullet->SetPosition(transform_.position_);

            // 発射した時間を更新
            lastFireTime_ = currentTime;
        }
    }
}

void Chara_Player::OnCollision(GameObject* pTarget)
{
    Score* score = dynamic_cast<Score*>(FindObject("Score"));

    // 無敵状態なら何もしない
    if (isInvincible_)
    {
        // 無敵時間が経過したかチェック
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> elapsedTime = currentTime - invincibleStartTime_;
        if (elapsedTime.count() >= invincibleDuration_)
        {
            isInvincible_ = false; // 無敵状態解除
            Image::SetAlpha(chara_Pict_, 255); // 透明度を元に戻す
        }
        else
        {
            return; // 無敵状態中なのでダメージを無効化
        }
    }

    //当たったときの処理
    //敵に当たるか弾に当たるかでピチュンします
    if (pTarget->GetObjectName() == "Chara_Enemy"|| pTarget->GetObjectName() == "EM_Bullet"
        || pTarget->GetObjectName() == "Big_Bullet")
    {
        if (player_Hp == 0)
        {
            score->StopCounting();
            score->SaveFinalScore();  // ゲーム終了時に最終スコアを保存
            this->KillMe();
            SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
            pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
        }
        else
        {
            player_Hp--;
            isInvincible_ = true; // 無敵状態にする
            invincibleStartTime_ = std::chrono::steady_clock::now(); // 無敵時間の開始
        }
    }
}

// 残機に応じたスコア倍率を返す関数
float Chara_Player::GetScoreMultiplier() const
{
    if (player_Hp == 2)
    {
        return 1.5;  // 残機3の場合は1.3倍
    }
    else if (player_Hp == 1)
    {
        return 1.3;  // 残機2の場合は1.2倍
    }
    else
    {
        return 1.0;  // 残機1の場合は1.0倍
    }
}