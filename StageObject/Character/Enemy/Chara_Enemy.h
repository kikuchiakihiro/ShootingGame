#pragma once
#include "../../../Engine/GameObject.h"
#include "../../Gauge/Boss_HpGauge.h"

enum  EnemyState
{
    HIGHHEALTH,   // �̗͂��������̏��
    MEDIUMHEALTH, // �̗͂������炢�̎��̏��
    LOWHEALTH     // �̗͂��Ⴂ���̏��
};

class Chara_Enemy : public GameObject
{
private:
    int enemy_Pict_;
    int enemy_Health_;  // �̗�
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
   
    // �R���X�g���N�^
    Chara_Enemy(GameObject* parent);
    
    // �f�X�g���N�^
    ~Chara_Enemy();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �`��
    void Draw() override;

    // �J��
    void Release() override;

    void OnCollision(GameObject* pTarget) override;

    void ChangeHealthState();  // �̗͂ɉ����ď�Ԃ�ύX

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

