#include "Big_Bullet.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"
//コンストラクタ
Big_Bullet::Big_Bullet(GameObject* parent)
    :GameObject(parent, "Big_Bullet"), Big_Bullet_Pict_(-1),speed_(0.005)
{
}

//デストラクタ
Big_Bullet::~Big_Bullet()
{
}

//初期化
void Big_Bullet::Initialize()
{
    Big_Bullet_Pict_ = Image::Load("Bullet/Boss_Bullet_P.png");
    assert(Big_Bullet_Pict_ >= 0);
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.19f);
    AddCollider(collision);

    
}

//更新
void Big_Bullet::Update()
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


    float bulletWidth = 2.f; // 例: 弾の幅
    float bulletHeight = 2.f; // 例: 弾の高さ

    // 画面外に出た場合の判定
    if (transform_.position_.x < -bulletWidth || transform_.position_.x > screenWidth + bulletWidth ||
        transform_.position_.y < -bulletHeight || transform_.position_.y > screenHeight + bulletHeight)
    {
        KillMe();
    }

}

//描画
void Big_Bullet::Draw()
{
    Image::SetTransform(Big_Bullet_Pict_, transform_);
    Image::Draw(Big_Bullet_Pict_);
}

//開放
void Big_Bullet::Release()
{
}
