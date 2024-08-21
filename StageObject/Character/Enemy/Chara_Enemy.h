#pragma once
#include "../../Engine/GameObject.h"

class Chara_Enemy : public GameObject
{
private:
    int enemy_Pict_;
    float enemy_Speed_;
    float enemy_Direction_; // �ړ������i�Ⴆ�΁A0.0f = �E�A1.0f = ���j
    

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
};

