#include "bg_GameOver.h"
#include "../../Engine/Image.h"
bg_GameOver::bg_GameOver(GameObject* parent) 
	: GameObject(parent, "bg_GameOver"), bg_Pict_GameOver_(-1)
{
}

bg_GameOver::~bg_GameOver()
{
}

void bg_GameOver::Initialize()
{
	// 画像データのロード
	bg_Pict_GameOver_ = Image::Load("bg/bg_GameOver.png");
	assert(bg_Pict_GameOver_ >= 0);

	pText = new Text;
	pText->Initialize();

	// スコアマネージャーから最終スコアを取得

	finalScore_ = Score::GetFinalScore();  // 保存された最終スコアを取得
}

void bg_GameOver::Update()
{
}

void bg_GameOver::Draw()
{
	Image::SetTransform(bg_Pict_GameOver_, transform_);
	Image::Draw(bg_Pict_GameOver_);
	pText->Draw(drawX + 450, drawY + 100, "Final Score");
	pText->Draw(drawX + 700, drawY + 100, finalScore_);
}

void bg_GameOver::Release()
{

}
