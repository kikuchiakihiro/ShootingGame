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
void Score::AddScoreWin(int amount)
{
    score_ += amount;
}
// スコアをプレイヤーの残機に基づいて加算
void Score::AddScore(int amount, Chara_Player* player)
{
    float multiplier = player->GetScoreMultiplier();  // プレイヤーの残機に応じた倍率を取得
    score_ += static_cast<int>(amount * multiplier);  // スコアに倍率を掛けて加算
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







