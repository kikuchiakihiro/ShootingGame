#include "Chara_Enemy.h"
#include "../../../Engine/Image.h"
#include "../../Engine/SphereCollider.h"

Chara_Enemy::Chara_Enemy(GameObject* parent)
	: GameObject(parent, "Chara_Enemy"), enemy_Pict_(-1), enemy_Speed_(0.01f), enemy_Direction_(0.0f)
{
}

Chara_Enemy::~Chara_Enemy()
{
}

void Chara_Enemy::Initialize()
{
	
	// �摜�f�[�^�̃��[�h
	enemy_Pict_ = Image::Load("Character/Enemy_Red.png");
	assert(enemy_Pict_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.005f);
	AddCollider(collision);

	transform_.scale_.x = 3;
	transform_.scale_.y = 3;
	transform_.scale_.z = 3;
}

void Chara_Enemy::Update()
{
	//// �G�̈ړ��i��: ���E�Ɉړ��j
	//if (enemy_Direction_ == 0.0f) // �E����
	//	transform_.position_.x += enemy_Speed_;
	//else if (enemy_Direction_ == 1.0f) // ������
	//	transform_.position_.y += enemy_Speed_;

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
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Bullet")
	{
		this->KillMe();
		pTarget->KillMe();
		
	}
}
