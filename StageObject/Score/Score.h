#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"

class Score : public GameObject
{
private:
    Text* pText;
    int score_;  // �X�R�A�̕ϐ�
    float timer_;  // �^�C�}�[�p�̕ϐ�
    int drawX, drawY; //�\���ʒu
public:
    // �R���X�g���N�^
    Score(GameObject* parent);

    // �f�X�g���N�^
    ~Score();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �`��
    void Draw() override;

    // �J��
    void Release() override;

    // �X�R�A�����Z����֐�
    void AddScore(int amount);
};
