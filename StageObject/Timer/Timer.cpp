#include "Timer.h"

static const int FPS = 60;
//コンストラクタ
Timer::Timer(GameObject* parent)
    :GameObject(parent, "Timer"), pText(nullptr), active(false), drawX(0), drawY(0)
{
}

//デストラクタ
Timer::~Timer()
{

}

//初期化
void Timer::Initialize()
{
    pText = new Text;

    pText->Initialize();

    frame = 0;
    active = false;
}

//更新
void Timer::Update()
{
    active = true;
    if (active) //frameがactiveの時
    {
        if (frame >= 0)
        {
            
            frame++; //0で止まる
        }
    }

}

//描画
void Timer::Draw()
{
    pText->Draw(drawX + 1000, drawY + 50, "Time");
    int sec = frame / FPS;
    pText->Draw(drawX + 1100, drawY + 50, sec);

}

//開放
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