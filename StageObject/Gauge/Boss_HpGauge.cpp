#include "Boss_HpGauge.h"
#include "../../Engine/Image.h"

// �R���X�g���N�^
Boss_HpGauge::Boss_HpGauge(GameObject* parent)
    : GameObject(parent, "Boss_HpGauge"), maxHealth_(0), currentHealth_(0)  // �����l��ݒ�
{
}

// �f�X�g���N�^
Boss_HpGauge::~Boss_HpGauge()
{
}

// ���������\�b�h
void Boss_HpGauge::Initialize()
{
    // �̗̓Q�[�W�p�̉摜�f�[�^�̃��[�h
    Boss_HpGauge_Pict_ = Image::Load("Gauge/Boss_HpBar.png");
    assert(Boss_HpGauge_Pict_ >= 0);

    position_ = { -0.25f,0.9f,0.0f };
    scale_ = { 1000.0f,1.0f, 0.0f, };
}

// �ő�̗͂�ݒ肷�郁�\�b�h
void Boss_HpGauge::SetMaxHealth(int maxHealth)
{
    maxHealth_ = maxHealth;
    currentHealth_ = maxHealth;  // ���݂̗̑͂��ő�̗͂ɍ��킹�ă��Z�b�g
}

// �X�V
void Boss_HpGauge::Update()
{
    // �Q�[�W�̃X�P�[����̗͂Ɋ�Â��čX�V
    scale_.x = static_cast<float>(currentHealth_) / maxHealth_;
    transform_.position_ = position_;  // �ʒu���X�V
    transform_.scale_ = scale_;  // �X�P�[�����X�V
}

// �`��
void Boss_HpGauge::Draw()
{
    // �̗͂ɉ������X�P�[���ŃQ�[�W��`��
    Image::SetTransform(Boss_HpGauge_Pict_, transform_);
    Image::Draw(Boss_HpGauge_Pict_);
}

// �̗͂����炷
void Boss_HpGauge::DecreaseHealth(int amount)
{
    currentHealth_ -= amount;
    if (currentHealth_ < 0)
    {
        currentHealth_ = 0;
    }
}

// �̗͂�ݒ肷��
void Boss_HpGauge::SetHealth(int health)
{
    currentHealth_ = health;
    if (currentHealth_ > maxHealth_)
    {
        currentHealth_ = maxHealth_;
    }
}

// �J��
void Boss_HpGauge::Release()
{
    // �K�v�ɉ����ă��\�[�X�̊J�����s��
}
