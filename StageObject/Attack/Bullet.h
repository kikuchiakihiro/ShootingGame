#pragma once
#include "../../Engine/GameObject.h"

class Bullet : public GameObject
{
private:
    int bullet_Pict_;      // �e�̉摜�n���h��
    float speed_;          // �e�̈ړ����x
    float direction_;      // �e�̈ړ������i�p�x�j

public:
    // �R���X�g���N�^
    Bullet(GameObject* parent);

    // �f�X�g���N�^
    ~Bullet();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �`��
    void Draw() override;

    // �e�̐ݒ�
    void SetDirection(float _direction);
    void SetSpeed(float _speed);

    // �J��
    void Release() override;
};

