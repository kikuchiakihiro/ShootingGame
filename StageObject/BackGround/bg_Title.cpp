#include "bg_Title.h"
#include "../../Engine/Image.h"

bg_Title::bg_Title(GameObject* parent)
    : GameObject(parent, "bg_Title"), bg_Pict_(-1)
{
}

bg_Title::~bg_Title()
{
}

void bg_Title::Initialize()
{
    // 画像データのロード
    bg_Pict_ = Image::Load("bg/bg_Title_DEMO.png");
    assert(bg_Pict_ >= 0);

}

void bg_Title::Update()
{

}

void bg_Title::Draw()
{

    Image::SetTransform(bg_Pict_, transform_);
    Image::Draw(bg_Pict_);

}

void bg_Title::Release()
{
}