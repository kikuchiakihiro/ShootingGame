#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"

//◆◆◆を管理するクラス
class Timer : public GameObject
{
private:

    float frame; //残り時間を数える変数
    Text* pText;
    bool active; //trueの時にカウントダウンする
    int drawX, drawY; //表示位置
public:
    //コンストラクタ
    Timer(GameObject* parent);

    //デストラクタ
    ~Timer();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;


    /// <summary>
    /// 制限時間を秒で設定する
    /// </summary>
    /// <param name="seconds"></param>
    void SetLimit(float seconds);

    /// <summary>
    /// タイマーを開始
    /// </summary>
    void Start();

    /// <summary>
    /// タイマーを停止
    /// </summary>
    void Stop();

    /// <summary>
    /// タイマーが終了したか
    /// </summary>
    /// <returns></returns>
    bool IsFinished();

    /// <summary>
    /// 表示位置を指定
    /// </summary>
    /// <param name="x">X座標</param>
    /// <param name="y">Y座標</param>
    void DrawPosition(int x, int y) { drawX = x; drawY = y; };
};