#pragma once
#include "../../../../../Engine/GameObject.h"
#include "../../../../../Engine/Text.h"
#include "../StageObject/Score/Score.h"
class Scene_ClearResult : public GameObject
{
private:
	Text* pText;
	int finalScore_;  // 保存された最終スコア
	int drawX, drawY; //表示位置
	
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Scene_ClearResult(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};
