#include "bg_ScoreBoard.h"
#include "../../Engine/Image.h"

bg_ScoreBoard::bg_ScoreBoard(GameObject* parent)
    : GameObject(parent, "bg_ScoreBoard"), bg_Pict_(-1)
{
}

bg_ScoreBoard::~bg_ScoreBoard()
{
}

void bg_ScoreBoard::Initialize()
{
    // 画像データのロード
    bg_Pict_ = Image::Load("bg/bg_ScoreBoard.png");
    assert(bg_Pict_ >= 0);

    //transform_.position_.x = 0.25f;
    //transform_.scale_.x = 0.75f;
}

void bg_ScoreBoard::Update()
{
 
}

void bg_ScoreBoard::Draw()
{
    
    Image::SetTransform(bg_Pict_, transform_);
    Image::Draw(bg_Pict_);

}

void bg_ScoreBoard::Release()
{
}