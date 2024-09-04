#pragma once
#include "../../../../../Engine/GameObject.h"
#include "../../../../../Engine/Text.h"
class Scene_ClearResult : public GameObject
{
private:
	Text* pText;
	int drawX, drawY; //�\���ʒu
	int finalScore;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Scene_ClearResult(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};
