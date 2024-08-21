#pragma once
#include "../../Engine/GameObject.h"

class Bullet : public GameObject
{
private:
    int bullet_Pict_;      // 弾の画像ハンドル
    float speed_;          // 弾の移動速度
    float direction_;      // 弾の移動方向（角度）

public:
    // コンストラクタ
    Bullet(GameObject* parent);

    // デストラクタ
    ~Bullet();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    // 弾の設定
    void SetDirection(float _direction);
    void SetSpeed(float _speed);

    // 開放
    void Release() override;
};

