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
        // 0.01秒ごとにスコアを1増やす
        timer_ += 0.01f;
        if (timer_ >= 0.01f)
        {
            score_ += 1;
            timer_ -= 0.01f;  // タイマーをリセット
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

// 最終スコアを保存
void Score::SaveFinalScore()
{
    finalScore_ = score_;
}

// 最終スコアを取得
int Score::GetFinalScore() 
{
    return finalScore_;
}


