#pragma once
#include "../../Engine/GameObject.h"

//���������Ǘ�����N���X
class Big_Bullet : public GameObject
{
private:
    int Big_Bullet_Pict_;
    XMFLOAT3 direction_;
    float angle_;
    float speed_;

public:
    //�R���X�g���N�^
    Big_Bullet(GameObject* parent);

    //�f�X�g���N�^
    ~Big_Bullet();

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
    void SetAngle(float _angle) { angle_ = _angle; }

};

