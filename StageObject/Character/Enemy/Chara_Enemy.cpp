#include "Chara_Enemy.h"
#include "../../../Engine/Image.h"
#include "../../../Engine/BoxCollider.h"
#include "../../Attack/EM_Bullet.h"
#include <chrono>

Chara_Enemy::Chara_Enemy(GameObject* parent)
	: GameObject(parent, "Chara_Enemy"), enemy_Pict_(-1)
	, enemy_Health_(100), shootInterval_(0.5f), timeSinceLastShot_(0.0f), shootOffset_(0.1f), rengeAngle_(10)
{
}

Chara_Enemy::~Chara_Enemy()
{
}

void Chara_Enemy::Initialize()
{
	
	// �摜�f�[�^�̃��[�h
	enemy_Pict_ = Image::Load("Character/Boss_Space_256.png");
	assert(enemy_Pict_ >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.35f,0.0005f,0.0f));
	AddCollider(collision);

	transform_.position_ = {-0.25f,0.5f,0.0f};
	//transform_.scale_ = {10,10,0};
	
}

void Chara_Enemy::Update()
{
	rengeTime_++;
	Spiralshoot();

}

void Chara_Enemy::Draw()
{
	Image::SetTransform(enemy_Pict_, transform_);
	Image::Draw(enemy_Pict_);
}

void Chara_Enemy::Release()
{
}

void Chara_Enemy::OnCollision(GameObject* pTarget)
{
	// ���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Bullet")
	{
		enemy_Health_--;  // �̗͂�1���炷

		if (enemy_Health_ <= 0)  // �̗͂�0�ȉ��Ȃ����
		{
			this->KillMe();
		}

		pTarget->KillMe();  // �e������
	}
}

void Chara_Enemy::Spiralshoot()
{
	
	if (rengeTime_ % 40 == 0) // �e�𔭎˂���^�C�~���O
	{
		
		for (int i = 0; i < 36; i++) // �e��36���A10�x����]�����Ĕ���
		{
			EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
			XMFLOAT3 position = { transform_.position_.x, transform_.position_.y, transform_.position_.z };
			pBullet->SetPosition(position);
			pBullet->SetAngle(i * rengeAngle_ + (rengeTime_ % 360)); // 10�x����]������
		}
	}
	if (rengeTime_ % 80 == 0) // �e�𔭎˂���^�C�~���O
	{

		for (int i = 0; i < 40; i++) // �e��36���A10�x����]�����Ĕ���
		{
			EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
			XMFLOAT3 position = { transform_.position_.x, transform_.position_.y, transform_.position_.z };
			pBullet->SetPosition(position);
			pBullet->SetAngle(i * rengeAngle_+6 + (rengeTime_ % 360)); // 10�x����]������
		}
	}
}

