#pragma once
#include "../../Engine/GameObject.h"

//◆◆◆を管理するクラス
class EM_Bullet : public GameObject
{
private:
    int EM_Bullet_Pict_;
    XMFLOAT3 direction_;
    float speed_;
    float angle_;
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
};

