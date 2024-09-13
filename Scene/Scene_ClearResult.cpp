#include "Scene_ClearResult.h"
#include "../StageObject/Score/Score.h"
#include "../StageObject/BackGround/bg_Clear.h"
//#include "../../../../../Engine/SceneManager.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"
Scene_ClearResult::Scene_ClearResult(GameObject* parent)
	:GameObject(parent, "Scene_ClearResult")
{
}

void Scene_ClearResult::Initialize()
{
	Instantiate<bg_Clear>(this);
	
}

void Scene_ClearResult::Update()
{
	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}

}

void Scene_ClearResult::Draw()
{	
	
}

void Scene_ClearResult::Release()
{
}

