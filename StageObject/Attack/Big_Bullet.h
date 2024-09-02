#pragma once
#include "../../Engine/GameObject.h"

//◆◆◆を管理するクラス
class Big_Bullet : public GameObject
{
private:
    int Big_Bullet_Pict_;
    XMFLOAT3 direction_;
    float angle_;
    float speed_;

public:
    //コンストラクタ
    Big_Bullet(GameObject* parent);

    //デストラクタ
    ~Big_Bullet();

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
    void SetAngle(float _angle) { angle_ = _angle; }

};

