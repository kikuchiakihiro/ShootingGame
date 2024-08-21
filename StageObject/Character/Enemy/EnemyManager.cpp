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
    // �K�v�ɉ����ď������R�[�h��ǉ�
}

void EnemyManager::Update()
{
    // �o�ߎ��Ԃ��X�V
    elapsedTime_ += 1.0f / 60.0f; // 60 FPS�̏ꍇ�A1�t���[���̌o�ߎ��Ԃ�1/60�b

    // ��莞�Ԃ��o�߂�����G�𐶐�
    if (elapsedTime_ >= spawnTime_)
    {
        SpawnEnemy();
        elapsedTime_ = 0.0f; // �o�ߎ��Ԃ����Z�b�g
    }

    // �G�̍X�V
    for (Chara_Enemy* enemy : enemies_)
    {
        enemy->Update();
    }
}

void EnemyManager::Draw()
{
    // �G�̕`��
    for (Chara_Enemy* enemy : enemies_)
    {
        enemy->Draw();
    }
}

void EnemyManager::Release()
{
    // �G�I�u�W�F�N�g�̊J��
    for (Chara_Enemy* enemy : enemies_)
    {
        delete enemy;
    }
    enemies_.clear();
}

void EnemyManager::SpawnEnemy()
{
    // �V�����G�𐶐����A���X�g�ɒǉ�
    Chara_Enemy* newEnemy = new Chara_Enemy(this);
    newEnemy->Initialize();
    enemies_.push_back(newEnemy);
}
