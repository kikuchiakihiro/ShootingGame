#pragma once
#include "../../Engine/GameObject.h"
class bg_ScoreBoard : public GameObject
{
private:
    int bg_Pict_SB_;
   
public:
    //�R���X�g���N�^
    bg_ScoreBoard(GameObject* parent);

    //�f�X�g���N�^
    ~bg_ScoreBoard();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

