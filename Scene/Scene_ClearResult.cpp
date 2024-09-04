#include "Scene_ClearResult.h"
#include "../StageObject/Score/Score.h"
Scene_ClearResult::Scene_ClearResult(GameObject* parent)
{
}

void Scene_ClearResult::Initialize()
{
	pText = new Text;
	pText->Initialize();
}

void Scene_ClearResult::Update()
{
	

}

void Scene_ClearResult::Draw()
{
	
	pText->Draw(drawX + 1000, drawY + 100, "Score");
}

void Scene_ClearResult::Release()
{
}
