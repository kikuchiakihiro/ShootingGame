#pragma once
#include "../../Engine/GameObject.h"
enum BulletType
{
    NORMAL,   // �ʏ�̒e
    SPREAD    // �g�U����e
};
//���������Ǘ�����N���X
class EM_Bullet : public GameObject
{
   
private:
    int EM_Bullet_Pict_;
    XMFLOAT3 direction_;
    float speed_;
    float angle_;

    
    BulletType bulletType_;  // �e�̎�ނ�ێ�
    float spreadingTime_;    // �g�U�J�n����
    float timeElapsed_;      // �o�ߎ���
    bool isSpreading_;       // �g�U�����ǂ����̃t���O
    float spreadAngle_;      // �g�U����p�x
public:
    
    //�R���X�g���N�^
    EM_Bullet(GameObject* parent);

    //�f�X�g���N�^
    ~EM_Bullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetPosition(XMFLOAT3 _position)
    {
        transform_.position_.x = _position.x;
        transform_.position_.y = _position.y;
        transform_.position_.z = _position.z;
    }
    void SetAngle(float _angle){angle_ = _angle;}
    
    void SetBulletImage(const std::string& imagePath);  // �摜��؂�ւ��郁�\�b�h

    void SetBulletType(BulletType type) {bulletType_ = type;}
    // �e�̎�ނ�ݒ�

    // ���ʂ̃V���b�g�̃��W�b�N�i������Update�p�j
    void UpdateNormalShot();

    // �g�U����V���b�g�̃��W�b�N
    void UpdateSpreadShot();

    // �X�s�[�h�ݒ�
    void SetSpeed(float speed) { speed_ = speed; }
   
    void SetSpreadingTime(float time)
    {
        spreadingTime_ = time;
        timeElapsed_ = 0.0f;
        isSpreading_ = false;
    }// �g�U�J�n���Ԃ�ݒ�
    void SetSpreadAngle(float angle)
    {
        spreadAngle_ = angle;
    }// �g�U���̊p�x��ݒ�

   
};

