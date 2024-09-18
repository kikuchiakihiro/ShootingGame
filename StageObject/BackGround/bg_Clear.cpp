#include "bg_Clear.h"
#include "../../Engine/Image.h"
bg_Clear::bg_Clear(GameObject* parent)
	: GameObject(parent, "bg_Clear"), bg_Pict_Clear_(-1)
{
}

bg_Clear::~bg_Clear()
{
}

void bg_Clear::Initialize()
{
	// �摜�f�[�^�̃��[�h
	bg_Pict_Clear_ = Image::Load("bg/bg_StageClear.png");
	assert(bg_Pict_Clear_ >= 0);
	pText = new Text;
	pText->Initialize();

	// �X�R�A�}�l�[�W���[����ŏI�X�R�A���擾
	
		finalScore_ = Score::GetFinalScore();  // �ۑ����ꂽ�ŏI�X�R�A���擾
		highScore_ = Score::GetHighScore();    // �n�C�X�R�A���擾
}

void bg_Clear::Update()
{
}

void bg_Clear::Draw()
{
	Image::SetTransform(bg_Pict_Clear_, transform_);
	Image::Draw(bg_Pict_Clear_);
	pText->Draw(drawX + 100, drawY + 400, "Final Score");
	pText->Draw(drawX + 300, drawY + 400, finalScore_);

	// �n�C�X�R�A�̕\��
	pText->Draw(drawX + 100, drawY + 450, "High Score:");
	pText->Draw(drawX + 300, drawY + 450, highScore_);


  
	
}

void bg_Clear::Release()
{

}
