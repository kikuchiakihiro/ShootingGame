#include "Scene_Play.h"
#include "../StageObject/BackGround/bg_Stage1.h"
#include "../StageObject/Character/Chara_Player.h"
#include "../StageObject/Character/Enemy/Chara_Enemy.h"
Scene_Play::Scene_Play(GameObject* parent)
	: GameObject(parent, "Scene_Play")
{
}

void Scene_Play::Initialize()
{
	
	Instantiate<bg_Stage1>(this);
	Instantiate<Chara_Player>(this);
	Instantiate<Chara_Enemy>(this);
}

void Scene_Play::Update()
{
}

void Scene_Play::Draw()
{
}

void Scene_Play::Release()
{
}
