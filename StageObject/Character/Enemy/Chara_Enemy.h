#pragma once
#include "../../../Engine/GameObject.h"
#include "../../Gauge/Boss_HpGauge.h"
#include "../../../Engine/VFX.h"
#include <chrono> // �^�C�}�[�p�̃��C�u����
enum  EnemyState
{
    WAVE1,  
    WAVE2, 
    WAVE3,
    WAVE4,
    WAVE5 
};
enum AttackState { ATTACK, INTERVAL } ; // �U�����
class Chara_Enemy : public GameObject
{
private:
    EmitterData Efedata = {};

    int enemy_Pict_;
    int previousImage_;
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
   
    bool isInvincible_; // ���G��Ԃ��ǂ���
    std::chrono::steady_clock::time_point invincibleStartTime_; // ���G��Ԃ̊J�n����
    float invincibleDuration_; // ���G���ԁi��: 2�b�ԁj

    float sceneChangeDelay_; // �V�[���`�F���W�܂ł̒x������
    float sceneChangeTimer_; // �^�C�}�[
    bool waitingForSceneChange_; // �V�[���`�F���W�ҋ@�t���O

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

    void Effect();

    void ChangeHealthState();  // �̗͂ɉ����ď�Ԃ�ύX

    void Spiralshoot();

    void BigShoot();


    void SetShootOffset(float _offset)
    {
        shootOffset_ = _offset;
    }
    // �v���C���[�̈ʒu�Ɍ������Ēe�����U��
    void AimAtPlayerShoot();

    void WaveShoot();

    void SpreadShoot();

    
};

