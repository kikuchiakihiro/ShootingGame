#pragma once
#include "../../Engine/GameObject.h"
enum BulletType
{
    NORMAL,   // 通常の弾
    SPREAD    // 拡散する弾
};
//◆◆◆を管理するクラス
class EM_Bullet : public GameObject
{
   
private:
    int EM_Bullet_Pict_;
    XMFLOAT3 direction_;
    float speed_;
    float angle_;

    
    BulletType bulletType_;  // 弾の種類を保持
    float spreadingTime_;    // 拡散開始時間
    float timeElapsed_;      // 経過時間
    bool isSpreading_;       // 拡散中かどうかのフラグ
    float spreadAngle_;      // 拡散する角度
public:
    
    //コンストラクタ
    EM_Bullet(GameObject* parent);

    //デストラクタ
    ~EM_Bullet();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetPosition(XMFLOAT3 _position)
    {
        transform_.position_.x = _position.x;
        transform_.position_.y = _position.y;
        transform_.position_.z = _position.z;
    }
    void SetAngle(float _angle){angle_ = _angle;}
    
    void SetBulletImage(const std::string& imagePath);  // 画像を切り替えるメソッド

    void SetBulletType(BulletType type) {bulletType_ = type;}
    // 弾の種類を設定

    // 普通のショットのロジック（既存のUpdate用）
    void UpdateNormalShot();

    // 拡散するショットのロジック
    void UpdateSpreadShot();

    // スピード設定
    void SetSpeed(float speed) { speed_ = speed; }
   
    void SetSpreadingTime(float time)
    {
        spreadingTime_ = time;
        timeElapsed_ = 0.0f;
        isSpreading_ = false;
    }// 拡散開始時間を設定
    void SetSpreadAngle(float angle)
    {
        spreadAngle_ = angle;
    }// 拡散時の角度を設定

   
};

