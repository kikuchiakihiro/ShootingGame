#pragma once
#include "Chara_Enemy.h"
#include <vector>

class EnemyManager : public GameObject
{
private:
    std::vector<Chara_Enemy*> enemies_;  // 敵オブジェクトのリスト
    float elapsedTime_;            // 経過時間
    float spawnTime_; // 敵が出現するまでの時間（秒）

public:
    // コンストラクタ
    EnemyManager(GameObject* parent);

    // デストラクタ
    ~EnemyManager();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    // 開放
    void Release() override;

    // 敵を生成する
    void SpawnEnemy();
};
