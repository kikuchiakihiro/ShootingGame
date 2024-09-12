#pragma once
#include "../Engine/GameObject.h"

class Scene_Title : public GameObject
{
private:
	inline static bool autoFireEnabled_ = false;  // 自動発射モードのフラグ
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Scene_Title(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	// 自動発射を設定する関数
	static void SetAutoFire(bool enabled) { autoFireEnabled_ = enabled; }

	// 自動発射が有効かを返す関数
	static bool IsAutoFireEnabled()  { return autoFireEnabled_; }
};

