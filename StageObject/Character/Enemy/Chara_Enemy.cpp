#include "Chara_Enemy.h"
#include "../../../Engine/Image.h"
#include "../../../Engine/BoxCollider.h"
#include "../../Attack/EM_Bullet.h"
#include "../../Score/Score.h"
#include "../../Attack/Big_Bullet.h"
#include "../../../Engine/SceneManager.h"
#include "../../Character/Chara_Player.h"
#include <chrono>



Chara_Enemy::Chara_Enemy(GameObject* parent)
	: GameObject(parent, "Chara_Enemy"), enemy_Pict_(-1)
	, enemy_Health_(500), timeSinceLastShot_(0.0f), shootOffset_(0.1f), rengeAngle_(10)
	, shootDuration_(3.0f), intervalTime_(1.0f), currentTime_(0.0f), attackState_(ATTACK)
	, isInvincible_(false), invincibleDuration_(0.5f),sceneChangeDelay_(3.0f), sceneChangeTimer_(0.0f), waitingForSceneChange_(false)

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
	case WAVE1:
		//Spiralshoot();
		SpreadShoot();
		break;
	case WAVE2:
		AimAtPlayerShoot();
		BigShoot();
		break;
	case WAVE3:
		WaveShoot();  // �̗͂��������̍U��
		break;
	case WAVE4:
		Spiralshoot();
		break;
	case WAVE5:
		Spiralshoot();
		AimAtPlayerShoot();
		BigShoot();
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
	VFX::Release();
}

void Chara_Enemy::OnCollision(GameObject* pTarget)
{
	Chara_Player* player = dynamic_cast<Chara_Player*>(FindObject("Chara_Player"));
	Score* score = dynamic_cast<Score*>(FindObject("Score"));
	// ���������Ƃ��̏���
 	if (pTarget->GetObjectName() == "Bullet")
	{ 
		
		//Effect();

		enemy_Health_--;  // �̗͂�1���炷
		Hp->SetHealth(enemy_Health_);  // �̗̓Q�[�W���X�V
		// �X�R�A��100�_���Z
		score->AddScore(100,player);
			
		if (enemy_Health_ <= 0)  // �̗͂�0�ȉ��Ȃ����
		{
			score->AddScore(10000,player);
			score->StopCounting();
			score->SaveFinalScore();  // �Q�[���I�����ɍŏI�X�R�A��ۑ�
			this->KillMe();
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_CLEARRESULT);
		}
		pTarget->KillMe();  // �e������
		
	}
}

void Chara_Enemy::Effect()
{
	// �G�t�F�N�g�f�[�^�̍쐬
		
	
	Efedata.textureFileName = "Effect/flashC_R.png";
	Efedata.position = XMFLOAT3(-1.8f, 1.8f, 0.0f);
	Efedata.positionRnd = XMFLOAT3(0, 0, 0);  // �G�t�F�N�g��e�����������ʒu�Ŕ���������
	Efedata.isBillBoard = false;
	Efedata.rotate.x = 90;
	Efedata.delay = 0;
	Efedata.number = 1;
	Efedata.lifeTime = 7;
	Efedata.speed = 0;
	Efedata.size = XMFLOAT2(3, 3);
	Efedata.sizeRnd = XMFLOAT2(0, 0);
	Efedata.scale = XMFLOAT2(1.f, 1.f);
	Efedata.color = XMFLOAT4(1, 1, 1, 0.7f);

	VFX::Start(Efedata);
		
}


void Chara_Enemy::ChangeHealthState()
{
	if (enemy_Health_ > 400)
	{
		currentState_ = WAVE1;
	}
	else if (enemy_Health_ > 300)
	{
		currentState_ = WAVE2;
	}
	else if (enemy_Health_ > 200)
	{
		currentState_ = WAVE3;
	}
	else if (enemy_Health_ > 100)
	{
		currentState_ = WAVE4;
	}
	else if (enemy_Health_ >= 0)
	{
		currentState_ = WAVE5;
	}
}

void Chara_Enemy::Spiralshoot()
{
	
	if (rengeTime_ % 40 == 0) // �e�𔭎˂���^�C�~���O
	{
		
		for (int i = 0; i < 36; i++) // �e��36���A10�x����]�����Ĕ���
		{
			EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
			pBullet->SetBulletType(NORMAL);
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
			pBullet->SetBulletType(NORMAL);
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
					pBullet->SetBulletType(NORMAL);
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

void Chara_Enemy::WaveShoot()
{
	// ���˃^�C�~���O�̐ݒ�
	if (rengeTime_ % 30 == 0)  // ��: 30�t���[�����Ƃɔ���
	{
		const int numBullets = 40;  // ���˂���e�̐�
		const float waveFrequency = 0.1f;  // �g�̎��g���i�����\�j
		const float waveAmplitude = 1.0f;  // �g�̐U���i�����\�j

		// �e�̔��ˈʒu��ݒ�
		XMFLOAT3 startPosition = { transform_.position_.x, transform_.position_.y, transform_.position_.z };

		for (int i = 0; i < numBullets; i++)
		{
			EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
			pBullet->SetBulletType(NORMAL);
			float angle = i * (360.0f / numBullets);  // �e�̊p�x���ϓ��ɕ��z

			// �g��̈ʒu���v�Z
			float waveOffset = waveAmplitude * sinf(waveFrequency * rengeTime_ + XMConvertToRadians(angle));
			XMFLOAT3 bulletPosition = { startPosition.x + waveOffset, startPosition.y, startPosition.z };

			pBullet->SetPosition(bulletPosition);
			pBullet->SetAngle(angle);  // �e�̊p�x��ݒ�
		}
	}

	// �g��e���̔��˂ɍ��킹�ēG�̏�Ԃ��X�V����Ȃ�
	// �����ɑ��̍U���p�^�[�����ԊǗ��̃R�[�h��ǉ����邱�Ƃ��ł��܂��B
}

void Chara_Enemy::SpreadShoot()
{
	if (rengeTime_ % 60 == 0)  // 60�t���[�����Ƃɒe�𔭎�
	{
		const int numBullets = 20;  // ���˂���e�̐�
		XMFLOAT3 enemyPosition = { transform_.position_.x, transform_.position_.y, transform_.position_.z };

		// �v���C���[�̈ʒu���擾
		Chara_Player* pPlayer = dynamic_cast<Chara_Player*>(FindObject("Chara_Player"));
		if (pPlayer)
		{
			XMFLOAT3 playerPosition = pPlayer->GetPosition();

			// 3�����ɒe�𔭎�: -90�x (��), 45�x (�E��), 135�x (����)
			const float initialAngles[3] = { -90.0f, 45.0f, 135.0f };

			for (int j = 0; j < 3; j++)  // 3�̈قȂ�p�x
			{
				for (int i = 0; i < numBullets; i++)  // �e�����ɕ����̒e�𔭎�
				{
					EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
					pBullet->SetBulletType(SPREAD);
					pBullet->SetPosition(enemyPosition);

					if (initialAngles[j] == -90.0f)  // �^���̒e�̓v���C���[��_��
					{
						// �v���C���[�̈ʒu�������p�x���v�Z
						float deltaX = playerPosition.x - enemyPosition.x;
						float deltaY = playerPosition.y - enemyPosition.y;
						float angle = atan2f(deltaY, deltaX) * 180.0f / XM_PI;
						pBullet->SetAngle(angle);
					}
					else  // ���̊p�x�͂��̂܂ܐݒ�
					{
						pBullet->SetAngle(initialAngles[j]);
					}

					// �g�U����^�C�~���O��ݒ�
					pBullet->SetSpeed(0.015);
					pBullet->SetSpreadingTime(0.2f);  // 0.2�b��Ɋg�U
					pBullet->SetSpreadAngle(i * (360.0f / numBullets));  // �g�U����p�x��ݒ�
				}
			}
		}
	}
}
