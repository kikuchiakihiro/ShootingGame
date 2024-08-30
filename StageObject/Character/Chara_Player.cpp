#include "Chara_Player.h"
#include "../../StageObject/Attack/Bullet.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"  
#include "../../Engine/SphereCollider.h"

Chara_Player::Chara_Player(GameObject* parent)
    : GameObject(parent, "Chara_Player"), chara_Pict_(-1), chara_speed_(0.01f), chara_width_(64.f), chara_height_(64.f)
    , screenWidth_(1280.f), screenHeight_(720.f),maxScreenX(64.47f), maxScreenY(65.f),minScreen(-0.97f)
{
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

    transform_.position_ = { -0.25f,-0.5f,0.0f };
}

void Chara_Player::Update()
{
    Move();  // 移動処理を呼び出す
    Shot();
}

void Chara_Player::Draw()
{
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
    //通常弾の発射はスペースキー
    if (Input::IsKeyDown(DIK_SPACE))
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent());
        pBullet->SetPosition(transform_.position_);
    }
}

void Chara_Player::OnCollision(GameObject* pTarget)
{
    //当たったときの処理
    //敵に当たるか弾に当たるかでピチュンします
    if (pTarget->GetObjectName() == "Chara_Enemy")
    {
        this->KillMe();
        pTarget->KillMe();
    }
    if (pTarget->GetObjectName() == "EM_Bullet")
    {
        this->KillMe();
        pTarget->KillMe();


    }
}

