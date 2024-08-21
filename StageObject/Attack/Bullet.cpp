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
    // �摜�f�[�^�̃��[�h
    bullet_Pict_ = Image::Load("Bullet/Enemy_Bullet.png");
    assert(bullet_Pict_ >= 0);

    transform_.scale_.x = 1;
    transform_.scale_.y = 1;
    transform_.scale_.z = 1;
}

void Bullet::Update()
{
    // �e�̈ړ��i��: ���i�j
    transform_.position_.x += cosf(direction_) * speed_;
    transform_.position_.y += sinf(direction_) * speed_;

    // ��ʊO�ɏo����폜����i���ɒP���ȍ폜���@�Ƃ��āj
    if (transform_.position_.x < 0 || transform_.position_.x > 1280 ||
        transform_.position_.y < 0 || transform_.position_.y > 720)
    {
        // �I�u�W�F�N�g�̍폜�i�ڍׂȍ폜���@�̓v���W�F�N�g�̎d�l�ɍ��킹�Ă��������j
        delete this; // ����������폜
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