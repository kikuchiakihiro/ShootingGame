#pragma once
#include "../../../Engine/GameObject.h"
#include "../../Gauge/Boss_HpGauge.h"

enum  EnemyState
{
    HIGHHEALTH,   // 体力が高い時の状態
    MEDIUMHEALTH, // 体力が中くらいの時の状態
    LOWHEALTH     // 体力が低い時の状態
};

class Chara_Enemy : public GameObject
{
private:
    int enemy_Pict_;
    int enemy_Health_;  // 体力
    int rengeTime_;

    float rengeAngle_;
    float shotAngle_;
    float shotSpeed_;
    float shootInterval_;
    float timeSinceLastShot_;
    float shootOffset_;

    EnemyState currentState_;
    Boss_HpGauge* Hp = new Boss_HpGauge(this);

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

    void ChangeHealthState();  // 体力に応じて状態を変更

    void Spiralshoot();

    void BigShoot();

    void SetShootInterval(float _interval)
    {
        shootInterval_ = _interval;
    }

    void SetShootOffset(float _offset)
    {
        shootOffset_ = _offset;
    }
};

