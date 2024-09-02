#pragma once

#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"

class Boss_HpGauge : public GameObject
{
private:
    int maxHealth_;  // �ő�̗�
    int currentHealth_;  // ���݂̗̑�
    int Boss_HpGauge_Pict_;  // �̗̓Q�[�W�̉摜
    XMFLOAT3 position_;  // �Q�[�W�̕\���ʒu
    XMFLOAT3 scale_;  // �Q�[�W�̃X�P�[���i�����𒲐��j

public:
    // �R���X�g���N�^
    Boss_HpGauge(GameObject* parent);

    // �f�X�g���N�^
    ~Boss_HpGauge();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �`��
    void Draw() override;

    void SetMaxHealth(int maxHealth);
    // �̗͂����炷
    void DecreaseHealth(int amount);

    // �̗͂�ݒ肷��
    void SetHealth(int health);

    // �J��
    void Release() override;
};
