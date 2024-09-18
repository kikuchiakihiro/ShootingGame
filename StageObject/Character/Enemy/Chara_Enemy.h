#pragma once
#include "../../../Engine/GameObject.h"
#include "../../Gauge/Boss_HpGauge.h"
#include "../../../Engine/VFX.h"
#include <chrono> // タイマー用のライブラリ
enum  EnemyState
{
    WAVE1,  
    WAVE2, 
    WAVE3,
    WAVE4,
    WAVE5 
};
enum AttackState { ATTACK, INTERVAL } ; // 攻撃状態
class Chara_Enemy : public GameObject
{
private:
    EmitterData Efedata = {};

    int enemy_Pict_;
    int previousImage_;
    int enemy_Health_;  // 体力
    int rengeTime_;
    int nowScore_;

    float rengeAngle_;
    float shotAngle_;
    float shotSpeed_;
    float timeSinceLastShot_;
    float shootOffset_;
    float shootDuration_; // 弾幕を撃ち続ける時間
    float intervalTime_; // インターバルの時間
    float currentTime_;

    AttackState attackState_;
    EnemyState currentState_;
    Boss_HpGauge* Hp = new Boss_HpGauge(this);
   
    bool isInvincible_; // 無敵状態かどうか
    std::chrono::steady_clock::time_point invincibleStartTime_; // 無敵状態の開始時間
    float invincibleDuration_; // 無敵時間（例: 2秒間）

    float sceneChangeDelay_; // シーンチェンジまでの遅延時間
    float sceneChangeTimer_; // タイマー
    bool waitingForSceneChange_; // シーンチェンジ待機フラグ

public:
   
    // コンストラクタ
    Chara_Enemy(GameObject* parent);
    
    // デストラクタ
    ~Chara_Enemy();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    // 開放
    void Release() override;

    void OnCollision(GameObject* pTarget) override;

    void Effect();

    void ChangeHealthState();  // 体力に応じて状態を変更

    void Spiralshoot();

    void BigShoot();


    void SetShootOffset(float _offset)
    {
        shootOffset_ = _offset;
    }
    // プレイヤーの位置に向かって弾を撃つ攻撃
    void AimAtPlayerShoot();

    void WaveShoot();

    void SpreadShoot();

    
};

