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

	// スコアマネージャーから最終スコアを取得
	{
		finalScore_ = Score::GetFinalScore();  // 保存された最終スコアを取得
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

