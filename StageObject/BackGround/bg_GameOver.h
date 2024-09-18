#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"
#include "../../StageObject/Score/Score.h"
class bg_GameOver : public GameObject
{
private:
    int bg_Pict_GameOver_;
    int drawX, drawY; //表示位置
    Text* pText;
    int finalScore_;  // 保存された最終スコア
public:
    //コンストラクタ
    bg_GameOver(GameObject* parent);

    //デストラクタ
    ~bg_GameOver();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};



