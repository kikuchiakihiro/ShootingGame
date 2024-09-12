#include "Scene_Title.h"
#include "../../../../../StageObject/BackGround/bg_Title.h"
#include "../../../../../Engine/SceneManager.h"
#include "../Engine/Input.h"
Scene_Title::Scene_Title(GameObject* parent)
	: GameObject(parent, "Scene_Title")
{
}

void Scene_Title::Initialize()
{
	Instantiate<bg_Title>(this);
}

void Scene_Title::Update()
{
	if (Input::IsKeyDown(DIK_LSHIFT))
	{
		Scene_Title::SetAutoFire(!Scene_Title::IsAutoFireEnabled());  // Ž©“®”­ŽË‚ÆŽè“®”­ŽË‚ðØ‚è‘Ö‚¦
	}
	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void Scene_Title::Draw()
{
}

void Scene_Title::Release()
{
}
