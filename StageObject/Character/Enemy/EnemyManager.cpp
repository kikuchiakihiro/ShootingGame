#include "EnemyManager.h"

EnemyManager::EnemyManager(GameObject* parent)
	: GameObject(parent, "EnemyManager"), elapsedTime_(0.0f), spawnTime_(1.0f)
{
}

EnemyManager::~EnemyManager()
{
    for (Chara_Enemy* enemy : enemies_)
    {
        delete enemy;
    }
}

void EnemyManager::Initialize()
{
    // 必要に応じて初期化コードを追加
}

void EnemyManager::Update()
{
    // 経過時間を更新
    elapsedTime_ += 1.0f / 60.0f; // 60 FPSの場合、1フレームの経過時間は1/60秒

    // 一定時間が経過したら敵を生成
    if (elapsedTime_ >= spawnTime_)
    {
        SpawnEnemy();
        elapsedTime_ = 0.0f; // 経過時間をリセット
    }

    // 敵の更新
    for (Chara_Enemy* enemy : enemies_)
    {
        enemy->Update();
    }
}

void EnemyManager::Draw()
{
    // 敵の描画
    for (Chara_Enemy* enemy : enemies_)
    {
        enemy->Draw();
    }
}

void EnemyManager::Release()
{
    // 敵オブジェクトの開放
    for (Chara_Enemy* enemy : enemies_)
    {
        delete enemy;
    }
    enemies_.clear();
}

void EnemyManager::SpawnEnemy()
{
    // 新しい敵を生成し、リストに追加
    Chara_Enemy* newEnemy = new Chara_Enemy(this);
    newEnemy->Initialize();
    enemies_.push_back(newEnemy);
}
