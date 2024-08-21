#include "Chara_Player.h"
#include "../../Engine/Image.h"
#include "../../Engine/Input.h"  // キー入力を処理するために追加

Chara_Player::Chara_Player(GameObject* parent)
    : GameObject(parent, "Chara_Player"), chara_Pict_(-1), chara_speed_(0.01f), chara_width_(64.f), chara_height_(64.f)
    , screenWidth_(1280.f), screenHeight_(720.f),maxScreen(65.f),minScreen(-1.0f)
{
}

Chara_Player::~Chara_Player()
{
    
}

void Chara_Player::Initialize()
{
    // 画像データのロード
    chara_Pict_ = Image::Load("Character/Player_Back.png");
    assert(chara_Pict_ >= 0);
}

void Chara_Player::Update()
{
    Move();  // 移動処理を呼び出す
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
    // 上に移動
    if (Input::IsKey(DIK_W))
    {
        transform_.position_.y += chara_speed_;
    }
    // 下に移動
    if (Input::IsKey(DIK_S))
    {
        transform_.position_.y -= chara_speed_;
    }
    // 左に移動
    if (Input::IsKey(DIK_A))
    {
        transform_.position_.x -= chara_speed_;
    }
    // 右に移動
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += chara_speed_;
    }
    
    // スクリーンの端でのループ処理
    transform_.position_.x = (transform_.position_.x < -chara_width_ / 2.0f) ? screenWidth_ + chara_width_ / 2.0f :
        (transform_.position_.x > screenWidth_ + chara_width_ / 2.0f) ? -chara_width_ / 2.0f :
        transform_.position_.x;

    transform_.position_.y = (transform_.position_.y < -chara_height_ / 2.0f) ? screenHeight_ + chara_height_ / 2.0f :
        (transform_.position_.y > screenHeight_ + chara_height_ / 2.0f) ? -chara_height_ / 2.0f :
        transform_.position_.y;

    // スクリーンの端に行かないように制限をかける
    transform_.position_.x = max(minScreen, min(transform_.position_.x, maxScreen - chara_width_));
    transform_.position_.y = max(minScreen, min(transform_.position_.y, maxScreen - chara_height_));
}


