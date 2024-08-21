#pragma once
#include "Chara_Enemy.h"
#include <vector>

class EnemyManager : public GameObject
{
private:
    std::vector<Chara_Enemy*> enemies_;  // �G�I�u�W�F�N�g�̃��X�g
    float elapsedTime_;            // �o�ߎ���
    float spawnTime_; // �G���o������܂ł̎��ԁi�b�j

public:
    // �R���X�g���N�^
    EnemyManager(GameObject* parent);

    // �f�X�g���N�^
    ~EnemyManager();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �`��
    void Draw() override;

    // �J��
    void Release() override;

    // �G�𐶐�����
    void SpawnEnemy();
};
