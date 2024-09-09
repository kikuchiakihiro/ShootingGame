#pragma once
#include "../../../../../Engine/GameObject.h"
class Scene_StageSelect : public GameObject
{
private:

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Scene_StageSelect(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};
