#include "Score.h"



Score::Score(GameObject* parent)
    : GameObject(parent, "Score"), pText(nullptr), timer_(0.0f), drawX(0), drawY(0),isCounting_(true)
    
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
    if (isCounting_)
    {
        // 0.01�b���ƂɃX�R�A��1���₷
        timer_ += 0.01f;
        if (timer_ >= 0.01f)
        {
            score_ += 1;
            timer_ -= 0.01f;  // �^�C�}�[�����Z�b�g
        }
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

void Score::StopCounting()
{
    isCounting_ = false;
}

void Score::StartCounting()
{
    isCounting_ = true;
}

// �ŏI�X�R�A��ۑ�
void Score::SaveFinalScore()
{
    finalScore_ = score_;
}

// �ŏI�X�R�A���擾
int Score::GetFinalScore() 
{
    return finalScore_;
}


