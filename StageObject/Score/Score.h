#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"

class Score : public GameObject
{
private:
    Text* pText;
    int score_;  // スコアの変数
    float timer_;  // タイマー用の変数
    int drawX, drawY; //表示位置
public:
    // コンストラクタ
    Score(GameObject* parent);

    // デストラクタ
    ~Score();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    // 開放
    void Release() override;

    // スコアを加算する関数
    void AddScore(int amount);
};

