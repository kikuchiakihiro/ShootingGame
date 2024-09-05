#include "Chara_Enemy.h"
#include "../../../Engine/Image.h"
#include "../../../Engine/BoxCollider.h"
#include "../../Attack/EM_Bullet.h"
#include "../../Score/Score.h"
#include "../../Attack/Big_Bullet.h"
#include <chrono>
#include "../../../Engine/SceneManager.h"




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
	enemy_Pict_ = Image::Load("Character/Boss_Space_512.png");
	assert(enemy_Pict_ >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.35f,0.0005f,0.0f));
	AddCollider(collision);

	transform_.position_ = {-0.25f,0.4f,0.0f};
	
	// HealthBar �̃C���X�^���X���쐬
	
	Hp->SetMaxHealth(enemy_Health_);  // �ő�̗͂�ݒ�
	Hp->Initialize();  // ������
}

void Chara_Enemy::Update()
{

	rengeTime_++;
	// �̗͂ɉ����ď�Ԃ�ύX
	ChangeHealthState();

	// ���݂̏�Ԃɉ������U�������s
	switch (currentState_)
	{
	case HIGHHEALTH:
		Spiralshoot();  // �̗͂��������̍U��
		break;
	case MEDIUMHEALTH:
		BigShoot();  // �̗͂������炢�̎��̍U��
		break;
	case LOWHEALTH:
		Spiralshoot();
		BigShoot();  // �̗͂��Ⴂ���̍U��
		break;
	default:
		break;
	}

	// HealthBar �̈ʒu�ƃX�P�[�����X�V
	Hp->Update();
	
}

void Chara_Enemy::Draw()
{
	Image::SetTransform(enemy_Pict_, transform_);
	Image::Draw(enemy_Pict_);

	// HealthBar ��`��
	Hp->Draw();
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
		Hp->SetHealth(enemy_Health_);  // �̗̓Q�[�W���X�V
		// �X�R�A��100�_���Z
		
		Score* score = dynamic_cast<Score*>(FindObject("Score"));
		
			score->AddScore(100);
		
		if (enemy_Health_ <= 0)  // �̗͂�0�ȉ��Ȃ����
		{
			score->StopCounting();
			this->KillMe();
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_CLEARRESULT);
		}

		pTarget->KillMe();  // �e������
	}
}

void Chara_Enemy::ChangeHealthState()
{
	if (enemy_Health_ > 70)
	{
		currentState_ = HIGHHEALTH;
	}
	else if (enemy_Health_ > 30)
	{
		currentState_ = MEDIUMHEALTH;
	}
	else
	{
		currentState_ = LOWHEALTH;
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
	if (rengeTime_ % 50 == 0) // �e�𔭎˂���^�C�~���O
	{

		for (int i = 0; i < 36; i++) // �e��36���A10�x����]�����Ĕ���
		{
			EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
			XMFLOAT3 position = { transform_.position_.x, transform_.position_.y, transform_.position_.z };
			pBullet->SetPosition(position);
			pBullet->SetAngle(i * rengeAngle_++ + (rengeTime_ % 360)); // 10�x����]������
		}
	}
}

void Chara_Enemy::BigShoot()
{
	// �傫�Ȓe�̔���
	if (rengeTime_ % 360 == 0)  // ��: 100�t���[�����Ƃɔ���
	{
		Big_Bullet* pBigBullet = Instantiate<Big_Bullet>(GetParent());  // ���x�ƃT�C�Y���w��
		XMFLOAT3 position = { transform_.position_.x, transform_.position_.y, transform_.position_.z };
		pBigBullet->SetPosition(position);
		pBigBullet->SetAngle(-90); // 10�x����]������
	}
}

