#include "bg_GameOver.h"
#include "../../Engine/Image.h"
bg_GameOver::bg_GameOver(GameObject* parent) 
	: GameObject(parent, "bg_GameOver"), bg_Pict_(-1)
{
}

bg_GameOver::~bg_GameOver()
{
}

void bg_GameOver::Initialize()
{
	// 画像データのロード
	bg_Pict_ = Image::Load("bg/bg_GameOver.png");
	assert(bg_Pict_ >= 0);
}

void bg_GameOver::Update()
{
}

void bg_GameOver::Draw()
{
	Image::SetTransform(bg_Pict_, transform_);
	Image::Draw(bg_Pict_);
}

void bg_GameOver::Release()
{
}
