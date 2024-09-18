#pragma once
#include "../../Engine/GameObject.h"
class bg_ScoreBoard : public GameObject
{
private:
    int bg_Pict_SB_;
   
public:
    //コンストラクタ
    bg_ScoreBoard(GameObject* parent);

    //デストラクタ
    ~bg_ScoreBoard();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

