#include "Scene_GameOver.h"
#include "../StageObject/BackGround/bg_GameOver.h"
//#include "../../../../../Engine/SceneManager.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"
Scene_GameOver::Scene_GameOver(GameObject* parent)
:GameObject(parent, "Scene_GameOver")
{
}

void Scene_GameOver::Initialize()
{
	Instantiate<bg_GameOver>(this);
}

void Scene_GameOver::Update()
{
	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
	if (Input::IsKeyDown(DIK_ESCAPE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void Scene_GameOver::Draw()
{

}

void Scene_GameOver::Release()
{

}
