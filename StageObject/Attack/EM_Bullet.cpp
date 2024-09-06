#include "EM_Bullet.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"
//�R���X�g���N�^
EM_Bullet::EM_Bullet(GameObject* parent)
    :GameObject(parent, "EM_Bullet"), EM_Bullet_Pict_(-1), speed_(0.02f)
{
}

//�f�X�g���N�^
EM_Bullet::~EM_Bullet()
{
}

//������
void EM_Bullet::Initialize()
{
    EM_Bullet_Pict_ = Image::Load("Bullet/Boss_Bullet_G.png");
    assert(EM_Bullet_Pict_ >= 0);
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.025f);
    AddCollider(collision);

    transform_.scale_ = {3,3,3};
}

//�X�V
void EM_Bullet::Update()
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

    
    float bulletWidth = 1.f; // ��: �e�̕�
    float bulletHeight = 1.f; // ��: �e�̍���

    // ��ʊO�ɏo���ꍇ�̔���
    if (transform_.position_.x < -bulletWidth || transform_.position_.x > screenWidth + bulletWidth ||
        transform_.position_.y < -bulletHeight || transform_.position_.y > screenHeight + bulletHeight)
    {
        KillMe();
    }
}

//�`��
void EM_Bullet::Draw()
{
    Image::SetTransform(EM_Bullet_Pict_, transform_);
    Image::Draw(EM_Bullet_Pict_);
}

//�J��
void EM_Bullet::Release()
{
}

void EM_Bullet::SetBulletImage(const std::string& imagePath)
{
    EM_Bullet_Pict_ = Image::Load(imagePath.c_str());
    assert(EM_Bullet_Pict_ >= 0);
}


