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
     Score::finalScore_ = score_;
     UpdateHighScore();     // ハイスコアをチェックして更新
}

void Score::UpdateHighScore()
{
    if (Score::finalScore_ > Score::highScore_)
    {
        Score::highScore_ = Score::finalScore_;  // ハイスコアを更新
    }
}







