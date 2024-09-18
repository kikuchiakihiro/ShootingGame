#include "Bullet.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"
//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), bullet_Pict_(-1)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
    bullet_Pict_ = Image::Load("Bullet/Player_Bullet.png");
    assert(bullet_Pict_ >= 0);
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.025f);
    AddCollider(collision);

    transform_.scale_.x = 3;
    transform_.scale_.y = 3;
    transform_.scale_.z = 3;
}

//�X�V
void Bullet::Update()
{

    transform_.position_.y += 0.05f;

    if (transform_.position_.y > 0.5f)
    {
        KillMe();
    }

}

//�`��
void Bullet::Draw()
{
    Image::SetTransform(bullet_Pict_, transform_);
    Image::Draw(bullet_Pict_);
}

//�J��
void Bullet::Release()
{

}
