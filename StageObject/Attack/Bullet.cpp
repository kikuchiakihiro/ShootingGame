#include "Bullet.h"
#include "../../Engine/Image.h"

Bullet::Bullet(GameObject* parent)
    : GameObject(parent, "Bullet"), bullet_Pict_(-1), direction_(0.0f), speed_(0.0f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
    // 画像データのロード
    bullet_Pict_ = Image::Load("Bullet/Enemy_Bullet.png");
    assert(bullet_Pict_ >= 0);

    transform_.scale_.x = 1;
    transform_.scale_.y = 1;
    transform_.scale_.z = 1;
}

void Bullet::Update()
{
    // 弾の移動（例: 直進）
    transform_.position_.x += cosf(direction_) * speed_;
    transform_.position_.y += sinf(direction_) * speed_;

    // 画面外に出たら削除する（仮に単純な削除方法として）
    if (transform_.position_.x < 0 || transform_.position_.x > 1280 ||
        transform_.position_.y < 0 || transform_.position_.y > 720)
    {
        // オブジェクトの削除（詳細な削除方法はプロジェクトの仕様に合わせてください）
        delete this; // メモリから削除
    }
}

void Bullet::Draw()
{
    Image::SetTransform(bullet_Pict_, transform_);
    Image::Draw(bullet_Pict_);
}

void Bullet::SetDirection(float _direction)
{
    direction_ = _direction;
}

void Bullet::SetSpeed(float _speed)
{
    speed_ = _speed;
}

void Bullet::Release()
{
    Image::Release(bullet_Pict_);
}