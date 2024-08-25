#pragma once
#include "../../Engine/GameObject.h"

//◆◆◆を管理するクラス
class Bullet : public GameObject
{
    int bullet_Pict_ ;
public:
    //コンストラクタ
    Bullet(GameObject* parent);

    //デストラクタ
    ~Bullet();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

