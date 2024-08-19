#include "bg_Stage1.h"
#include "../../Engine/Image.h"

bg_Stage1::bg_Stage1(GameObject* parent)
    : GameObject(parent, "bg_Stage1"), bg_Pict_(-1), scrollSpeed_(0.001f), bgOffsetY_(0.0f), bgHeight_(2)
{
}

bg_Stage1::~bg_Stage1()
{
}

void bg_Stage1::Initialize()
{
    // 画像データのロード
    bg_Pict_ = Image::Load("bg_Stage1.png");
    assert(bg_Pict_ >= 0);

    
}

void bg_Stage1::Update()
{
    // 背景画像のスクロール
    bgOffsetY_ += scrollSpeed_;

    // 画像が1ループしたらリセット
    if (bgOffsetY_ >= bgHeight_) {
        bgOffsetY_ -= bgHeight_;
    }
}

void bg_Stage1::Draw()
{
    // 1枚目の背景画像を描画
    transform_.position_.y = -bgOffsetY_;
    Image::SetTransform(bg_Pict_, transform_);
    Image::Draw(bg_Pict_);

    // 2枚目の背景画像を描画（1枚目の下に連続して描画）
    transform_.position_.y = -bgOffsetY_ + bgHeight_;
    Image::SetTransform(bg_Pict_, transform_);
    Image::Draw(bg_Pict_);
}

void bg_Stage1::Release()
{
}