#pragma once
#include "../../Engine/GameObject.h"
class bg_GameOver : public GameObject
{
private:
    int bg_Pict_;

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



