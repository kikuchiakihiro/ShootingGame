#pragma once
#include "../../Engine/GameObject.h"
//#include "../../../../../Engine/Text.h"
#include "../../Engine/Text.h"
#include "../../StageObject/Score/Score.h"
class bg_Clear : public GameObject
{
private:
    int bg_Pict_;
    Text* pText;
    int finalScore_;  // 保存された最終スコア
    int drawX, drawY; //表示位置
    int highScore_;
public:
    //コンストラクタ
    bg_Clear(GameObject* parent);

    //デストラクタ
    ~bg_Clear();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};



