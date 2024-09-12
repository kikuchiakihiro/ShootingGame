#include "Chara_Player.h"
#include "../../StageObject/Attack/Bullet.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"  
#include "../../Engine/SphereCollider.h"
#include "../../StageObject/Score/Score.h"
#include "../../Engine/SceneManager.h"
#include "../../Scene/Scene_Title.h"
Chara_Player::Chara_Player(GameObject* parent)
    : GameObject(parent, "Chara_Player"), chara_Pict_(-1), chara_speed_(0.01f), chara_width_(64.f), chara_height_(64.f)
    , screenWidth_(1280.f), screenHeight_(720.f),maxScreenX(64.47f), maxScreenY(65.f),minScreen(-0.97f), fireInterval_(0.15f)
    
{
    // �R���X�g���N�^�ōŌ�̔��ˎ��Ԃ����ݎ��Ԃɐݒ�
    lastFireTime_ = std::chrono::steady_clock::now();
}

Chara_Player::~Chara_Player()
{
    
}

void Chara_Player::Initialize()
{
    // �摜�f�[�^�̃��[�h
    chara_Pict_ = Image::Load("Character/Player_Back.png");
    assert(chara_Pict_ >= 0);
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.00005f);
    AddCollider(collision);

    transform_.position_ = { -0.25f,-0.5f,0.0f };
}

void Chara_Player::Update()
{
    Move();  // �ړ��������Ăяo��
    Shot();
}

void Chara_Player::Draw()
{
    Image::SetTransform(chara_Pict_, transform_);
    Image::Draw(chara_Pict_);
}

void Chara_Player::Release()
{
}

void Chara_Player::Move()
{
    // ��Ɉړ�
    if (Input::IsKey(DIK_W))
    {
        transform_.position_.y += chara_speed_;
    }
    // ���Ɉړ�
    if (Input::IsKey(DIK_S))
    {
        transform_.position_.y -= chara_speed_;
    }
    // ���Ɉړ�
    if (Input::IsKey(DIK_A))
    {
        transform_.position_.x -= chara_speed_;
    }
    // �E�Ɉړ�
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += chara_speed_;
    }
    
    // �X�N���[���̒[�ɓ�����܂�
    transform_.position_.x = (transform_.position_.x < -chara_width_ / 2.0f) ? screenWidth_ + chara_width_ / 2.0f :
        (transform_.position_.x > screenWidth_ + chara_width_ / 2.0f) ? -chara_width_ / 2.0f :
        transform_.position_.x;

    transform_.position_.y = (transform_.position_.y < -chara_height_ / 2.0f) ? screenHeight_ + chara_height_ / 2.0f :
        (transform_.position_.y > screenHeight_ + chara_height_ / 2.0f) ? -chara_height_ / 2.0f :
        transform_.position_.y;

    // �X�N���[���̒[�ɍs���Ȃ��悤�ɐ�����������
    transform_.position_.x = max(minScreen, min(transform_.position_.x, maxScreenX - chara_width_));
    transform_.position_.y = max(minScreen, min(transform_.position_.y, maxScreenY - chara_height_));
}



void Chara_Player::Shot()
{
    // ���݂̎��Ԃ��擾
    auto currentTime = std::chrono::steady_clock::now();

    // �O��̔��ˎ��Ԃ���̌o�ߎ��Ԃ��v�Z
    std::chrono::duration<float> elapsedTime = currentTime - lastFireTime_;

    if (Scene_Title::IsAutoFireEnabled())
    {
        // �������˃��[�h�̏ꍇ�A0.5�b���Ƃɒe�𔭎�
        if (elapsedTime.count() >= fireInterval_)
        {
            Bullet* pBullet = Instantiate<Bullet>(GetParent());
            pBullet->SetPosition(transform_.position_);

            // ���˂������Ԃ��X�V
            lastFireTime_ = currentTime;
        }
    }
    else
    {
        // �蓮���˃��[�h�i�X�y�[�X�L�[�Ŕ��ˁj
        if (Input::IsKeyDown(DIK_SPACE))
        {
            Bullet* pBullet = Instantiate<Bullet>(GetParent());
            pBullet->SetPosition(transform_.position_);
        }
    }
}

void Chara_Player::OnCollision(GameObject* pTarget)
{
    Score* score = dynamic_cast<Score*>(FindObject("Score"));
    //���������Ƃ��̏���
    //�G�ɓ����邩�e�ɓ����邩�Ńs�`�������܂�
    if (pTarget->GetObjectName() == "Chara_Enemy"|| pTarget->GetObjectName() == "EM_Bullet"
        || pTarget->GetObjectName() == "Big_Bullet")
    {
        score->StopCounting();
        this->KillMe();
        pTarget->KillMe();
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
    }
}

