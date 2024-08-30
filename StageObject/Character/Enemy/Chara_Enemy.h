#pragma once
#include "../../../Engine/GameObject.h"
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

    void Spiralshoot();

    void SetShootInterval(float _interval)
    {
        shootInterval_ = _interval;
    }

    void SetShootOffset(float _offset)
    {
        shootOffset_ = _offset;
    }
};

