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
// �X�R�A���v���C���[�̎c�@�Ɋ�Â��ĉ��Z
void Score::AddScore(int amount, Chara_Player* player)
{
    float multiplier = player->GetScoreMultiplier();  // �v���C���[�̎c�@�ɉ������{�����擾
    score_ += static_cast<int>(amount * multiplier);  // �X�R�A�ɔ{�����|���ĉ��Z
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
     Score::finalScore_ = score_;
     UpdateHighScore();     // �n�C�X�R�A���`�F�b�N���čX�V
}

void Score::UpdateHighScore()
{
    if (Score::finalScore_ > Score::highScore_)
    {
        Score::highScore_ = Score::finalScore_;  // �n�C�X�R�A���X�V
    }
}







