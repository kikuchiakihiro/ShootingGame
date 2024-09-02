#include "Score.h"


Score::Score(GameObject* parent)
    : GameObject(parent, "Score"), pText(nullptr), score_(0), timer_(0.0f), drawX(0), drawY(0)
{
}

Score::~Score()
{
}

void Score::Initialize()
{
    pText = new Text;

    pText->Initialize();
}

void Score::Update()
{
    // 0.01�b���ƂɃX�R�A��1���₷
    timer_ += 0.01f;
    if (timer_ >= 0.01f)
    {
        score_ += 1;
        timer_ -= 0.01f;  // �^�C�}�[�����Z�b�g
    }

  
}

void Score::Draw()
{
    pText->Draw(drawX + 1000, drawY + 100, "Score");
   
    pText->Draw(drawX + 1100, drawY + 100, score_);
}

void Score::Release()
{
    delete pText;
    pText = nullptr;
}

void Score::AddScore(int amount)
{
    score_ += amount;
}
