#pragma once
#include "../../Engine/GameObject.h"
class bg_Stage1 : public GameObject
{
private:
    int bg_Pict_Stage_;
    float scrollSpeed_;     // �X�N���[�����x
    float bgOffsetY_;       // �w�i�摜�̏c�I�t�Z�b�g
    int bgHeight_;          // �w�i�摜�̍���
public:
    //�R���X�g���N�^
    bg_Stage1(GameObject* parent);

    //�f�X�g���N�^
    ~bg_Stage1();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

