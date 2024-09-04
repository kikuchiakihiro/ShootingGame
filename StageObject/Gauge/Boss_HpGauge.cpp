#include "Boss_HpGauge.h"
#include "../../Engine/Image.h"

// コンストラクタ
Boss_HpGauge::Boss_HpGauge(GameObject* parent)
    : GameObject(parent, "Boss_HpGauge"), maxHealth_(0), currentHealth_(0)  // 初期値を設定
{
}

// デストラクタ
Boss_HpGauge::~Boss_HpGauge()
{
}

// 初期化メソッド
void Boss_HpGauge::Initialize()
{
    // 体力ゲージ用の画像データのロード
    Boss_HpGauge_Pict_ = Image::Load("Gauge/Boss_HpBar.png");
    assert(Boss_HpGauge_Pict_ >= 0);

    position_ = { -0.25f,0.9f,0.0f };
    scale_ = { 1000.0f,1.0f, 0.0f, };
}

// 最大体力を設定するメソッド
void Boss_HpGauge::SetMaxHealth(int maxHealth)
{
    maxHealth_ = maxHealth;
    currentHealth_ = maxHealth;  // 現在の体力も最大体力に合わせてリセット
}

// 更新
void Boss_HpGauge::Update()
{
    // ゲージのスケールを体力に基づいて更新
    scale_.x = static_cast<float>(currentHealth_) / maxHealth_;
    transform_.position_ = position_;  // 位置を更新
    transform_.scale_ = scale_;  // スケールを更新
}

// 描画
void Boss_HpGauge::Draw()
{
    // 体力に応じたスケールでゲージを描画
    Image::SetTransform(Boss_HpGauge_Pict_, transform_);
    Image::Draw(Boss_HpGauge_Pict_);
}

// 体力を減らす
void Boss_HpGauge::DecreaseHealth(int amount)
{
    currentHealth_ -= amount;
    if (currentHealth_ < 0)
    {
        currentHealth_ = 0;
    }
}

// 体力を設定する
void Boss_HpGauge::SetHealth(int health)
{
    currentHealth_ = health;
    if (currentHealth_ > maxHealth_)
    {
        currentHealth_ = maxHealth_;
    }
}

// 開放
void Boss_HpGauge::Release()
{
    // 必要に応じてリソースの開放を行う
}
