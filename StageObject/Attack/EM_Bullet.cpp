#include "EM_Bullet.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"
//コンストラクタ
EM_Bullet::EM_Bullet(GameObject* parent)
    :GameObject(parent, "EM_Bullet"), EM_Bullet_Pict_(-1), speed_(0.02f)
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

    // 弾の進行方向を計算
    float radian = XMConvertToRadians(angle_);
    direction_.x = cosf(radian) * speed_;
    direction_.y = sinf(radian) * speed_;

    // 弾を移動させる
    transform_.position_.x += direction_.x;
    transform_.position_.y += direction_.y;

    
    float screenWidth = -0.55f;
    float screenHeight = 0.1f;

    
    float bulletWidth = 1.f; // 例: 弾の幅
    float bulletHeight = 1.f; // 例: 弾の高さ

    // 画面外に出た場合の判定
    if (transform_.position_.x < -bulletWidth || transform_.position_.x > screenWidth + bulletWidth ||
        transform_.position_.y < -bulletHeight || transform_.position_.y > screenHeight + bulletHeight)
    {
        KillMe();
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


