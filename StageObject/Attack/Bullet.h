#pragma once
#include "../../Engine/GameObject.h"

//���������Ǘ�����N���X
class Bullet : public GameObject
{
    int bullet_Pict_ ;
public:
    //�R���X�g���N�^
    Bullet(GameObject* parent);

    //�f�X�g���N�^
    ~Bullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

