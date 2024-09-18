#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"
#include "../../StageObject/Score/Score.h"
class bg_GameOver : public GameObject
{
private:
    int bg_Pict_GameOver_;
    int drawX, drawY; //�\���ʒu
    Text* pText;
    int finalScore_;  // �ۑ����ꂽ�ŏI�X�R�A
public:
    //�R���X�g���N�^
    bg_GameOver(GameObject* parent);

    //�f�X�g���N�^
    ~bg_GameOver();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};



