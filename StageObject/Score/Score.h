#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"

class Score : public GameObject
{
private:
    Text* pText;
     int score_;  // �X�R�A�̕ϐ�
    int savedScore_;
    float timer_;  // �^�C�}�[�p�̕ϐ�
    int drawX, drawY; //�\���ʒu
    bool isCounting_; // �X�R�A�̃J�E���g���L�����ǂ���

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

    // �X�R�A�̃J�E���g���~����
    void StopCounting();

    // �X�R�A�̃J�E���g���ĊJ����i�K�v�ɉ����āj
    void StartCounting();

    void SetSaveScore() { savedScore_ = score_; }

    int GetScore()  { return savedScore_; }
};
