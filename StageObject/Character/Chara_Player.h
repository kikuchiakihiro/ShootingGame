#pragma once
#include "../../Engine/GameObject.h"

class Chara_Player : public GameObject
{
private:
    int chara_Pict_;
    float chara_width_;  // �v���C���[�̉摜�̕�
    float chara_height_; // �v���C���[�̉摜�̍���
    float screenWidth_;
    float screenHeight_;
    float maxScreen;
    float minScreen;
    float chara_speed_;

public:
    // �R���X�g���N�^
    Chara_Player(GameObject* parent);

    // �f�X�g���N�^
    ~Chara_Player();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �`��
    void Draw() override;

    // �J��
    void Release() override;

    // �ړ�����
    void Move();
};