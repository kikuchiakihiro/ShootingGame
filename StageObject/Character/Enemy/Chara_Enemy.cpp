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
	: GameObject(parent, "Chara_Enemy"), normalImage_(-1)
	, enemy_Health_(500), timeSinceLastShot_(0.0f), shootOffset_(0.1f), rengeAngle_(10)
	, shootDuration_(3.0f), intervalTime_(1.0f), currentTime_(0.0f), attackState_(ATTACK)

{
}

Chara_Enemy::~Chara_Enemy()
{
}

void Chara_Enemy::Initialize()
{
	// 画像データのロード
	normalImage_ = Image::Load("Character/Boss_Space_512.png");
	assert(normalImage_ >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.35f,0.0005f,0.0f));
	AddCollider(collision);

	transform_.position_ = {-0.25f,0.4f,0.0f};
	
	// HealthBar のインスタンスを作成
	
	Hp->SetMaxHealth(enemy_Health_);  // 最大体力を設定
	Hp->Initialize();  // 初期化
}

void Chara_Enemy::Update()
{

	
	
	rengeTime_++;
	// 体力に応じて状態を変更
	ChangeHealthState();
	
	// 現在の状態に応じた攻撃を実行
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
		WaveShoot();  // 体力が高い時の攻撃
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

	// HealthBar の位置とスケールを更新
	Hp->Update();
	
}

void Chara_Enemy::Draw()
{
	Image::SetTransform(normalImage_, transform_);
	Image::Draw(normalImage_);
	Image::SetAlpha(normalImage_, 255);
	// HealthBar を描画
	Hp->Draw();
}

void Chara_Enemy::Release()
{
}

void Chara_Enemy::OnCollision(GameObject* pTarget)
{
	Score* score = dynamic_cast<Score*>(FindObject("Score"));
	// 当たったときの処理
 	if (pTarget->GetObjectName() == "Bullet")
	{
		enemy_Health_--;  // 体力を1減らす
		Hp->SetHealth(enemy_Health_);  // 体力ゲージを更新
		// スコアを100点加算
		
		
			score->AddScore(100);
			// 一瞬だけ画像を変更する処理
			//Image::SetAlpha(normalImage_, 128);
			
		if (enemy_Health_ <= 0)  // 体力が0以下なら消滅
		{
			
			score->AddScore(10000);
			score->StopCounting();
			score->SaveFinalScore();  // ゲーム終了時に最終スコアを保存
			this->KillMe();
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_CLEARRESULT);
		}

		pTarget->KillMe();  // 弾も消滅
	}
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
	
	if (rengeTime_ % 40 == 0) // 弾を発射するタイミング
	{
		
		for (int i = 0; i < 36; i++) // 弾を36発、10度ずつ回転させて発射
		{
			EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
			pBullet->SetBulletType(NORMAL);
			XMFLOAT3 position = { transform_.position_.x, transform_.position_.y, transform_.position_.z };
			pBullet->SetPosition(position);
			pBullet->SetAngle(i * rengeAngle_ + (rengeTime_ % 360)); // 10度ずつ回転させる
		}
	}
	if (rengeTime_ % 50 == 0) // 弾を発射するタイミング
	{

		for (int i = 0; i < 36; i++) // 弾を36発、10度ずつ回転させて発射
		{
			EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
			pBullet->SetBulletType(NORMAL);
			XMFLOAT3 position = { transform_.position_.x, transform_.position_.y, transform_.position_.z };
			pBullet->SetPosition(position);
			pBullet->SetAngle(i * rengeAngle_++ + (rengeTime_ % 360)); // 10度ずつ回転させる
		}
	}
}

void Chara_Enemy::BigShoot()
{
	// 大きな弾の発射
	if (rengeTime_ % 360 == 0)  // 例: 100フレームごとに発射
	{
		Big_Bullet* pBigBullet = Instantiate<Big_Bullet>(GetParent());  // 速度とサイズを指定
		XMFLOAT3 position = { transform_.position_.x, transform_.position_.y, transform_.position_.z };
		pBigBullet->SetPosition(position);
		pBigBullet->SetAngle(-90); // 10度ずつ回転させる
	}
}

void Chara_Enemy::AimAtPlayerShoot()
{
	Chara_Player* pPlayer = dynamic_cast<Chara_Player*>(FindObject("Chara_Player"));
	if (pPlayer)
	{
		currentTime_ += 0.01f;  // フレームごとの時間加算（例として0.01秒）

		switch (attackState_)
		{
		case ATTACK:
			if (currentTime_ <= shootDuration_)
			{
				// プレイヤーの位置を取得して、角度を計算
				XMFLOAT3 playerPosition = pPlayer->GetPosition();
				XMFLOAT3 enemyPosition = transform_.position_;

				float deltaX = playerPosition.x - enemyPosition.x;
				float deltaY = playerPosition.y - enemyPosition.y;
				float angle = atan2f(deltaY, deltaX) * 180.0f / XM_PI;

				// 弾を発射
				if (timeSinceLastShot_ >= shootOffset_)  // 弾の発射間隔
				{
					EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
					pBullet->SetBulletType(NORMAL);
					pBullet->SetPosition(enemyPosition);
					pBullet->SetAngle(angle);

					pBullet->SetBulletImage("Bullet/Boss_Bullet_Y.png");  // 自機狙いの弾の画像をセット
					timeSinceLastShot_ = 0.0f;  // 最後に発射した時間をリセット
				}
				else
				{
					timeSinceLastShot_ += 0.01f;  // フレームごとの時間加算
				}
			}
			else
			{
				// 攻撃終了、インターバルに切り替える
				attackState_ = INTERVAL;
				currentTime_ = 0.0f;  // インターバルの時間を追跡
			}
			break;

		case INTERVAL:
			if (currentTime_ >= intervalTime_)
			{
				// インターバル終了、再び攻撃に切り替える
				attackState_ = ATTACK;
				currentTime_ = 0.0f;  // 攻撃時間をリセット
			}
			break;
		}
	}
}

void Chara_Enemy::WaveShoot()
{
	// 発射タイミングの設定
	if (rengeTime_ % 30 == 0)  // 例: 30フレームごとに発射
	{
		const int numBullets = 50;  // 発射する弾の数
		const float waveFrequency = 0.1f;  // 波の周波数（調整可能）
		const float waveAmplitude = 1.0f;  // 波の振幅（調整可能）

		// 弾の発射位置を設定
		XMFLOAT3 startPosition = { transform_.position_.x, transform_.position_.y, transform_.position_.z };

		for (int i = 0; i < numBullets; i++)
		{
			EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
			pBullet->SetBulletType(NORMAL);
			float angle = i * (360.0f / numBullets);  // 弾の角度を均等に分配

			// 波状の位置を計算
			float waveOffset = waveAmplitude * sinf(waveFrequency * rengeTime_ + XMConvertToRadians(angle));
			XMFLOAT3 bulletPosition = { startPosition.x + waveOffset, startPosition.y, startPosition.z };

			pBullet->SetPosition(bulletPosition);
			pBullet->SetAngle(angle);  // 弾の角度を設定
		}
	}

	// 波状弾幕の発射に合わせて敵の状態を更新するなど
	// ここに他の攻撃パターンや状態管理のコードを追加することができます。
}

void Chara_Enemy::SpreadShoot()
{
	if (rengeTime_ % 60 == 0)  // 60フレームごとに弾を発射
	{
		const int numBullets = 20;  // 発射する弾の数
		XMFLOAT3 enemyPosition = { transform_.position_.x, transform_.position_.y, transform_.position_.z };

		// プレイヤーの位置を取得
		Chara_Player* pPlayer = dynamic_cast<Chara_Player*>(FindObject("Chara_Player"));
		if (pPlayer)
		{
			XMFLOAT3 playerPosition = pPlayer->GetPosition();

			// 3方向に弾を発射: -90度 (下), 45度 (右上), 135度 (左上)
			const float initialAngles[3] = { -90.0f, 45.0f, 135.0f };

			for (int j = 0; j < 3; j++)  // 3つの異なる角度
			{
				for (int i = 0; i < numBullets; i++)  // 各方向に複数の弾を発射
				{
					EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
					pBullet->SetBulletType(SPREAD);
					pBullet->SetPosition(enemyPosition);

					if (initialAngles[j] == -90.0f)  // 真下の弾はプレイヤーを狙う
					{
						// プレイヤーの位置を向く角度を計算
						float deltaX = playerPosition.x - enemyPosition.x;
						float deltaY = playerPosition.y - enemyPosition.y;
						float angle = atan2f(deltaY, deltaX) * 180.0f / XM_PI;
						pBullet->SetAngle(angle);
					}
					else  // 他の角度はそのまま設定
					{
						pBullet->SetAngle(initialAngles[j]);
					}

					// 拡散するタイミングを設定
					pBullet->SetSpeed(0.015);
					pBullet->SetSpreadingTime(0.2f);  // 0.2秒後に拡散
					pBullet->SetSpreadAngle(i * (360.0f / numBullets));  // 拡散する角度を設定
				}
			}
		}
	}
}
