#include "EM_Bullet.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"
//コンストラクタ
EM_Bullet::EM_Bullet(GameObject* parent)
    :GameObject(parent, "EM_Bullet"), EM_Bullet_Pict_(-1), speed_(0.02f) // デフォルトスピードを設定
{
}

//デストラクタ
EM_Bullet::~EM_Bullet()
{
}

//初期化
void EM_Bullet::Initialize()
{
    EM_Bullet_Pict_ = Image::Load("Bullet/Boss_Bullet_G.png");
    assert(EM_Bullet_Pict_ >= 0);
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.025f);
    AddCollider(collision);

    transform_.scale_ = {3,3,3};
}

//更新
void EM_Bullet::Update()
{
    
    switch (bulletType_)
    {
    case NORMAL:
        UpdateNormalShot();  // 普通のショット
        break;
    case SPREAD:
        UpdateSpreadShot();  // 拡散ショット
        break;
    }
}

//描画
void EM_Bullet::Draw()
{
    Image::SetTransform(EM_Bullet_Pict_, transform_);
    Image::Draw(EM_Bullet_Pict_);
}

//開放
void EM_Bullet::Release()
{
}

void EM_Bullet::SetBulletImage(const std::string& imagePath)
{
    EM_Bullet_Pict_ = Image::Load(imagePath.c_str());
    assert(EM_Bullet_Pict_ >= 0);
}

// 普通のショットの更新処理（元のコード）
void EM_Bullet::UpdateNormalShot()
{
    // 弾の進行方向を計算
    float radian = XMConvertToRadians(angle_);
    direction_.x = cosf(radian) * speed_;
    direction_.y = sinf(radian) * speed_;

    // 弾を移動させる
    transform_.position_.x += direction_.x;
    transform_.position_.y += direction_.y;

    float screenWidth = -0.55f;
    float screenHeight = 0.1f;

    float bulletWidth = 1.f;  // 弾の幅
    float bulletHeight = 1.f;  // 弾の高さ

    // 画面外に出た場合の判定
    if (transform_.position_.x < -bulletWidth || transform_.position_.x > screenWidth + bulletWidth ||
        transform_.position_.y < -bulletHeight || transform_.position_.y > screenHeight + bulletHeight)
    {
        KillMe();
    }
}

void EM_Bullet::UpdateSpreadShot()
{
    timeElapsed_ += 0.01f;  // フレームごとの時間加算

    if (timeElapsed_ < spreadingTime_)
    {
        // 下方向に移動
        transform_.position_.y -= speed_;
    }
    else if (!isSpreading_)
    {
        // 拡散開始
        SetAngle(spreadAngle_);
        isSpreading_ = true;
    }

    // 弾の移動処理（角度に従って移動）
    float radian = XMConvertToRadians(angle_);
    direction_.x = cosf(radian) * speed_;
    direction_.y = sinf(radian) * speed_;
    transform_.position_.x += direction_.x;
    transform_.position_.y += direction_.y;

    // 画面外に出た場合の判定
    float screenWidth = -0.55f;
    float screenHeight = 0.1f;
    float bulletWidth = 1.f;  // 弾の幅
    float bulletHeight = 1.f;  // 弾の高さ

    if (transform_.position_.x < -bulletWidth || transform_.position_.x > screenWidth + bulletWidth ||
        transform_.position_.y < -bulletHeight || transform_.position_.y > screenHeight + bulletHeight)
    {
        KillMe();
    }
}