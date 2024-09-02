#pragma once

#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"

class Boss_HpGauge : public GameObject
{
private:
    int maxHealth_;  // 最大体力
    int currentHealth_;  // 現在の体力
    int Boss_HpGauge_Pict_;  // 体力ゲージの画像
    XMFLOAT3 position_;  // ゲージの表示位置
    XMFLOAT3 scale_;  // ゲージのスケール（長さを調整）

public:
    // コンストラクタ
    Boss_HpGauge(GameObject* parent);

    // デストラクタ
    ~Boss_HpGauge();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    void SetMaxHealth(int maxHealth);
    // 体力を減らす
    void DecreaseHealth(int amount);

    // 体力を設定する
    void SetHealth(int health);

    // 開放
    void Release() override;
};
