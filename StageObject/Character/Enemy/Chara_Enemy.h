#pragma once
#include "../../../Engine/GameObject.h"
#include "../../Gauge/Boss_HpGauge.h"

enum  EnemyState
{
    HIGHHEALTH,   // �̗͂��������̏��
    MEDIUMHEALTH, // �̗͂������炢�̎��̏��
    LOWHEALTH     // �̗͂��Ⴂ���̏��
};
enum AttackState { ATTACK, INTERVAL } ; // �U�����
class Chara_Enemy : public GameObject
{
private:
    int enemy_Pict_;
    int enemy_Health_;  // �̗�
    int rengeTime_;
    int nowScore_;

    float rengeAngle_;
    float shotAngle_;
    float shotSpeed_;
    float timeSinceLastShot_;
    float shootOffset_;
    float shootDuration_; // �e�������������鎞��
    float intervalTime_; // �C���^�[�o���̎���
    float currentTime_;

    AttackState attackState_;
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


    void SetShootOffset(float _offset)
    {
        shootOffset_ = _offset;
    }
    // �v���C���[�̈ʒu�Ɍ������Ēe�����U��
    void AimAtPlayerShoot();

    
};

