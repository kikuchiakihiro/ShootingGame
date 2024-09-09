#include "Scene_ClearResult.h"
#include "../StageObject/Score/Score.h"
Scene_ClearResult::Scene_ClearResult(GameObject* parent)
	:GameObject(parent, "Scene_ClearResult")
{
}

void Scene_ClearResult::Initialize()
{
	pText = new Text;
	pText->Initialize();

	// �X�R�A�}�l�[�W���[����ŏI�X�R�A���擾
	{
		finalScore_ = Score::GetFinalScore();  // �ۑ����ꂽ�ŏI�X�R�A���擾
	}
}

void Scene_ClearResult::Update()
{
	

}

void Scene_ClearResult::Draw()
{
	
	
	
	pText->Draw(drawX + 900, drawY + 100, "FinalScore");
 	pText->Draw(drawX + 1100, drawY + 100, finalScore_);

	
}

void Scene_ClearResult::Release()
{
}

