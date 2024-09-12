#pragma once
#include "../../Engine/GameObject.h"
class bg_Title : public GameObject
{
private:
    int bg_Pict_;
    
public:
    //コンストラクタ
    bg_Title(GameObject* parent);

    //デストラクタ
    ~bg_Title();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

   
};



