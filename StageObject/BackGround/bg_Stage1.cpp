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
    // �摜�f�[�^�̃��[�h
    bg_Pict_ = Image::Load("bg_Stage1.png");
    assert(bg_Pict_ >= 0);

    
}

void bg_Stage1::Update()
{
    // �w�i�摜�̃X�N���[��
    bgOffsetY_ += scrollSpeed_;

    // �摜��1���[�v�����烊�Z�b�g
    if (bgOffsetY_ >= bgHeight_) {
        bgOffsetY_ -= bgHeight_;
    }
}

void bg_Stage1::Draw()
{
    // 1���ڂ̔w�i�摜��`��
    transform_.position_.y = -bgOffsetY_;
    Image::SetTransform(bg_Pict_, transform_);
    Image::Draw(bg_Pict_);

    // 2���ڂ̔w�i�摜��`��i1���ڂ̉��ɘA�����ĕ`��j
    transform_.position_.y = -bgOffsetY_ + bgHeight_;
    Image::SetTransform(bg_Pict_, transform_);
    Image::Draw(bg_Pict_);
}

void bg_Stage1::Release()
{
}