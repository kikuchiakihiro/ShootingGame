#include "Chara_Enemy.h"
#include "../../../Engine/Image.h"
#include "../../Engine/SphereCollider.h"

Chara_Enemy::Chara_Enemy(GameObject* parent)
	: GameObject(parent, "Chara_Enemy"), enemy_Pict_(-1), enemy_Speed_(0.01f), enemy_Direction_(0.0f)
	, enemy_Health_(10)
{
}

Chara_Enemy::~Chara_Enemy()
{
}

void Chara_Enemy::Initialize()
{
	
	// 画像データのロード
	enemy_Pict_ = Image::Load("Character/Boss_Space.png");
	assert(enemy_Pict_ >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.35f,0.0005f,0.0f));
	AddCollider(collision);

	transform_.position_ = {-0.25f,0.25f,0.0f};
	transform_.scale_ = {15,15,0};
	
}

void Chara_Enemy::Update()
{
	

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
	// 当たったときの処理
	if (pTarget->GetObjectName() == "Bullet")
	{
		enemy_Health_--;  // 体力を1減らす

		if (enemy_Health_ <= 0)  // 体力が0以下なら消滅
		{
			this->KillMe();
		}

		pTarget->KillMe();  // 弾も消滅
	}
}
