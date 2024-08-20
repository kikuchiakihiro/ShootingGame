#pragma once
#include "../../Engine/GameObject.h"

class Chara_Player : public GameObject
{
private:
    int chara_Pict_;
    float chara_width_;  // プレイヤーの画像の幅
    float chara_height_; // プレイヤーの画像の高さ
    float screenWidth_;
    float screenHeight_;
    float maxScreen;
    float minScreen;
    float chara_speed_;

public:
    // コンストラクタ
    Chara_Player(GameObject* parent);

    // デストラクタ
    ~Chara_Player();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    // 開放
    void Release() override;

    // 移動処理
    void Move();
};