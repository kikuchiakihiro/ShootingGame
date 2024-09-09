#include "Stage_Sound.h"
#include "../../Engine/Audio.h"
Stage_Sound::Stage_Sound(GameObject* parent)
:GameObject(parent,"Stage_Sound"), Stage_Sound_(-1)
{
}

Stage_Sound::~Stage_Sound()
{
}

void Stage_Sound::Initialize()
{
    //サウンドデータのロード

    Stage_Sound_ = Audio::Load("Bgm/Es-STAGE2.wav");

    assert(Stage_Sound_ >= 0);
}

void Stage_Sound::Update()
{
    Audio::Play(Stage_Sound_);
}

void Stage_Sound::Draw()
{
}

void Stage_Sound::Release()
{
}
