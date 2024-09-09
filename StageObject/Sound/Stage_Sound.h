#pragma once
#include "../../Engine/GameObject.h"
class Stage_Sound : public GameObject
{
private:
	int Stage_Sound_;    //サウンド番号
public:
    // コンストラクタ
    Stage_Sound(GameObject* parent);

    // デストラクタ
    ~Stage_Sound();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    // 開放
    void Release() override;
};

