#pragma once
#include "../../Engine/GameObject.h"

class Chara_Enemy : public GameObject
{
private:
    int enemy_Pict_;
    float enemy_Speed_;
    float enemy_Direction_; // 移動方向（例えば、0.0f = 右、1.0f = 下）
    

public:
    // コンストラクタ
    Chara_Enemy(GameObject* parent);

    // デストラクタ
    ~Chara_Enemy();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    // 開放
    void Release() override;
};

