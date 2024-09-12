#pragma once
#include "../../Engine/GameObject.h"
#include "../Attack/Bullet.h"
#include <chrono> // タイマー用のライブラリ
class Chara_Player : public GameObject
{
private:
    int chara_Pict_;
    float chara_width_;  // プレイヤーの画像の幅
    float chara_height_; // プレイヤーの画像の高さ
    float screenWidth_;
    float screenHeight_;
    float maxScreenX;
    float maxScreenY;
    float minScreen;
    float chara_speed_;

    float fireInterval_;  // 弾の発射間隔（秒）
    std::chrono::time_point<std::chrono::steady_clock> lastFireTime_;  // 最後に弾を発射した時間
   
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

    void Shot();

    void OnCollision(GameObject* pTarget) override;
};