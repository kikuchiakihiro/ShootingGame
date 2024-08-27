#include "Timer.h"

static const int FPS = 60;
//�R���X�g���N�^
Timer::Timer(GameObject* parent)
    :GameObject(parent, "Timer"), pText(nullptr), active(false), drawX(0), drawY(0)
{
}

//�f�X�g���N�^
Timer::~Timer()
{

}

//������
void Timer::Initialize()
{
    pText = new Text;

    pText->Initialize();

    frame = 0;
    active = false;
}

//�X�V
void Timer::Update()
{
    active = true;
    if (active) //frame��active�̎�
    {
        if (frame >= 0)
        {
            
            frame++; //0�Ŏ~�܂�
        }
    }

}

//�`��
void Timer::Draw()
{
    pText->Draw(drawX + 1000, drawY + 50, "Time");
    int sec = frame / FPS;
    pText->Draw(drawX + 1100, drawY + 50, sec);

}

//�J��
void Timer::Release()
{
}

void Timer::SetLimit(float seconds)
{
    frame = (seconds * 60.0f);
}

void Timer::Start()
{
    active = true;
}

void Timer::Stop()
{
    active = false;
}

bool Timer::IsFinished()
{
    return (frame == 0);
}