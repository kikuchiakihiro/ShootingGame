#pragma once
#include "../../Engine/GameObject.h"
class Stage_Sound : public GameObject
{
private:
	int Stage_Sound_;    //�T�E���h�ԍ�
public:
    // �R���X�g���N�^
    Stage_Sound(GameObject* parent);

    // �f�X�g���N�^
    ~Stage_Sound();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �`��
    void Draw() override;

    // �J��
    void Release() override;
};

