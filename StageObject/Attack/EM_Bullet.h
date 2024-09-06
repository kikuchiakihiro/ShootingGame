#pragma once
#include "../../Engine/GameObject.h"

//���������Ǘ�����N���X
class EM_Bullet : public GameObject
{
private:
    int EM_Bullet_Pict_;
    XMFLOAT3 direction_;
    float speed_;
    float angle_;
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
};

