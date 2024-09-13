#include "Big_Bullet.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"
//�R���X�g���N�^
Big_Bullet::Big_Bullet(GameObject* parent)
    :GameObject(parent, "Big_Bullet"), Big_Bullet_Pict_(-1),speed_(0.005)
{
}

//�f�X�g���N�^
Big_Bullet::~Big_Bullet()
{
}

//������
void Big_Bullet::Initialize()
{
    Big_Bullet_Pict_ = Image::Load("Bullet/Boss_Bullet_P.png");
    assert(Big_Bullet_Pict_ >= 0);
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.19f);
    AddCollider(collision);

    
}

//�X�V
void Big_Bullet::Update()
{

    // �e�̐i�s�������v�Z
    float radian = XMConvertToRadians(angle_);
    direction_.x = cosf(radian) * speed_;
    direction_.y = sinf(radian) * speed_;

    // �e���ړ�������
    transform_.position_.x += direction_.x;
    transform_.position_.y += direction_.y;


    float screenWidth = -0.55f;
    float screenHeight = 0.1f;


    float bulletWidth = 2.f; // ��: �e�̕�
    float bulletHeight = 2.f; // ��: �e�̍���

    // ��ʊO�ɏo���ꍇ�̔���
    if (transform_.position_.x < -bulletWidth || transform_.position_.x > screenWidth + bulletWidth ||
        transform_.position_.y < -bulletHeight || transform_.position_.y > screenHeight + bulletHeight)
    {
        KillMe();
    }

}

//�`��
void Big_Bullet::Draw()
{
    Image::SetTransform(Big_Bullet_Pict_, transform_);
    Image::Draw(Big_Bullet_Pict_);
}

//�J��
void Big_Bullet::Release()
{
}
