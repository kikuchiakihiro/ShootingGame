#pragma once
#include "../../Engine/GameObject.h"
//#include "../../../../../Engine/Text.h"
#include "../../Engine/Text.h"
#include "../../StageObject/Score/Score.h"
class bg_Clear : public GameObject
{
private:
    int bg_Pict_;
    Text* pText;
    int finalScore_;  // �ۑ����ꂽ�ŏI�X�R�A
    int drawX, drawY; //�\���ʒu
    int highScore_;
public:
    //�R���X�g���N�^
    bg_Clear(GameObject* parent);

    //�f�X�g���N�^
    ~bg_Clear();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};



