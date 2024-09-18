#pragma once
#include "../../Engine/GameObject.h"
class bg_Stage1 : public GameObject
{
private:
    int bg_Pict_Stage_;
    float scrollSpeed_;     // スクロール速度
    float bgOffsetY_;       // 背景画像の縦オフセット
    int bgHeight_;          // 背景画像の高さ
public:
    //コンストラクタ
    bg_Stage1(GameObject* parent);

    //デストラクタ
    ~bg_Stage1();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

