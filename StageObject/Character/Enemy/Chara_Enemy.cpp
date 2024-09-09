#include "Chara_Enemy.h"
#include "../../../Engine/Image.h"
#include "../../../Engine/BoxCollider.h"
#include "../../Attack/EM_Bullet.h"
#include "../../Score/Score.h"
#include "../../Attack/Big_Bullet.h"
#include <chrono>
#include "../../../Engine/SceneManager.h"
#include "../../Character/Chara_Player.h"




Chara_Enemy::Chara_Enemy(GameObject* parent)
	: GameObject(parent, "Chara_Enemy"), enemy_Pict_(-1)
	, enemy_Health_(10), timeSinceLastShot_(0.0f), shootOffset_(0.1f), rengeAngle_(10)
	, shootDuration_(3.0f), intervalTime_(1.0f), currentTime_(0.0f), attackState_(ATTACK)
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
		AimAtPlayerShoot();
		break;
	case LOWHEALTH:
		Spiralshoot();
		BigShoot();  // �̗͂��Ⴂ���̍U��
		AimAtPlayerShoot();
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
	Score* score = dynamic_cast<Score*>(FindObject("Score"));
	// ���������Ƃ��̏���
 	if (pTarget->GetObjectName() == "Bullet")
	{
		enemy_Health_--;  // �̗͂�1���炷
		Hp->SetHealth(enemy_Health_);  // �̗̓Q�[�W���X�V
		// �X�R�A��100�_���Z
		
		
			score->AddScore(100);

			
				
			
		if (enemy_Health_ <= 0)  // �̗͂�0�ȉ��Ȃ����
		{
			
			
			score->StopCounting();
			score->SaveFinalScore();  // �Q�[���I�����ɍŏI�X�R�A��ۑ�
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

void Chara_Enemy::AimAtPlayerShoot()
{
	Chara_Player* pPlayer = dynamic_cast<Chara_Player*>(FindObject("Chara_Player"));
	if (pPlayer)
	{
		currentTime_ += 0.01f;  // �t���[�����Ƃ̎��ԉ��Z�i��Ƃ���0.01�b�j

		switch (attackState_)
		{
		case ATTACK:
			if (currentTime_ <= shootDuration_)
			{
				// �v���C���[�̈ʒu���擾���āA�p�x���v�Z
				XMFLOAT3 playerPosition = pPlayer->GetPosition();
				XMFLOAT3 enemyPosition = transform_.position_;

				float deltaX = playerPosition.x - enemyPosition.x;
				float deltaY = playerPosition.y - enemyPosition.y;
				float angle = atan2f(deltaY, deltaX) * 180.0f / XM_PI;

				// �e�𔭎�
				if (timeSinceLastShot_ >= shootOffset_)  // �e�̔��ˊԊu
				{
					EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
					pBullet->SetPosition(enemyPosition);
					pBullet->SetAngle(angle);

					pBullet->SetBulletImage("Bullet/Boss_Bullet_Y.png");  // ���@�_���̒e�̉摜���Z�b�g
					timeSinceLastShot_ = 0.0f;  // �Ō�ɔ��˂������Ԃ����Z�b�g
				}
				else
				{
					timeSinceLastShot_ += 0.01f;  // �t���[�����Ƃ̎��ԉ��Z
				}
			}
			else
			{
				// �U���I���A�C���^�[�o���ɐ؂�ւ���
				attackState_ = INTERVAL;
				currentTime_ = 0.0f;  // �C���^�[�o���̎��Ԃ�ǐ�
			}
			break;

		case INTERVAL:
			if (currentTime_ >= intervalTime_)
			{
				// �C���^�[�o���I���A�ĂэU���ɐ؂�ւ���
				attackState_ = ATTACK;
				currentTime_ = 0.0f;  // �U�����Ԃ����Z�b�g
			}
			break;
		}
	}
}