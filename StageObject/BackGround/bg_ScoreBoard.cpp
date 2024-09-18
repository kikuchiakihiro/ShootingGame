#include "bg_ScoreBoard.h"
#include "../../Engine/Image.h"

bg_ScoreBoard::bg_ScoreBoard(GameObject* parent)
    : GameObject(parent, "bg_ScoreBoard"), bg_Pict_SB_(-1)
{
}

bg_ScoreBoard::~bg_ScoreBoard()
{
}

void bg_ScoreBoard::Initialize()
{
    // 画像データのロード
    bg_Pict_SB_ = Image::Load("bg/bg_ScoreBoard.png");
    assert(bg_Pict_SB_ >= 0);

}

void bg_ScoreBoard::Update()
{
 
}

void bg_ScoreBoard::Draw()
{
    
    Image::SetTransform(bg_Pict_SB_, transform_);
    Image::Draw(bg_Pict_SB_);

}

void bg_ScoreBoard::Release()
{

}