#pragma once
#include "../Engine/GameObject.h"

class Scene_Title : public GameObject
{
private:
	inline static bool autoFireEnabled_ = false;  // �������˃��[�h�̃t���O
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Scene_Title(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	// �������˂�ݒ肷��֐�
	static void SetAutoFire(bool enabled) { autoFireEnabled_ = enabled; }

	// �������˂��L������Ԃ��֐�
	static bool IsAutoFireEnabled()  { return autoFireEnabled_; }
};

