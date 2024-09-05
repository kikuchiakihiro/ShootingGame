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
	
	// 画像データのロード
	enemy_Pict_ = Image::Load("Character/Boss_Space_512.png");
	assert(enemy_Pict_ >= 0);
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
	case HIGHHEALTH:
		Spiralshoot();  // 体力が高い時の攻撃
		break;
	case MEDIUMHEALTH:
		BigShoot();  // 体力が中くらいの時の攻撃
		break;
	case LOWHEALTH:
		Spiralshoot();
		BigShoot();  // 体力が低い時の攻撃
		break;
	default:
		break;
	}

	// HealthBar の位置とスケールを更新
	Hp->Update();
	
}

void Chara_Enemy::Draw()
{
	Image::SetTransform(enemy_Pict_, transform_);
	Image::Draw(enemy_Pict_);

	// HealthBar を描画
	Hp->Draw();
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
		Hp->SetHealth(enemy_Health_);  // 体力ゲージを更新
		// スコアを100点加算
		
		Score* score = dynamic_cast<Score*>(FindObject("Score"));
		
			score->AddScore(100);
		
		if (enemy_Health_ <= 0)  // 体力が0以下なら消滅
		{
			score->StopCounting();
			this->KillMe();
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_CLEARRESULT);
		}

		pTarget->KillMe();  // 弾も消滅
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
	
	if (rengeTime_ % 40 == 0) // 弾を発射するタイミング
	{
		
		for (int i = 0; i < 36; i++) // 弾を36発、10度ずつ回転させて発射
		{
			EM_Bullet* pBullet = Instantiate<EM_Bullet>(GetParent());
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

