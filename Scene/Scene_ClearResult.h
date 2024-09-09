#pragma once
#include "../../../../../Engine/GameObject.h"
#include "../../../../../Engine/Text.h"
#include "../StageObject/Score/Score.h"
class Scene_ClearResult : public GameObject
{
private:
	Text* pText;
	int finalScore_;  // �ۑ����ꂽ�ŏI�X�R�A
	int drawX, drawY; //�\���ʒu
	
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
