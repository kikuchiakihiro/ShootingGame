#pragma once
//#include "../../../../../Engine/GameObject.h"
#include "../Engine/GameObject.h"
class Scene_GameOver : public GameObject
{
private:

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Scene_GameOver(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};

