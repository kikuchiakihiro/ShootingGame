#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"

//���������Ǘ�����N���X
class Timer : public GameObject
{
private:

    float frame; //�c�莞�Ԃ𐔂���ϐ�
    Text* pText;
    bool active; //true�̎��ɃJ�E���g�_�E������
    int drawX, drawY; //�\���ʒu
public:
    //�R���X�g���N�^
    Timer(GameObject* parent);

    //�f�X�g���N�^
    ~Timer();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;


    /// <summary>
    /// �������Ԃ�b�Őݒ肷��
    /// </summary>
    /// <param name="seconds"></param>
    void SetLimit(float seconds);

    /// <summary>
    /// �^�C�}�[���J�n
    /// </summary>
    void Start();

    /// <summary>
    /// �^�C�}�[���~
    /// </summary>
    void Stop();

    /// <summary>
    /// �^�C�}�[���I��������
    /// </summary>
    /// <returns></returns>
    bool IsFinished();

    /// <summary>
    /// �\���ʒu���w��
    /// </summary>
    /// <param name="x">X���W</param>
    /// <param name="y">Y���W</param>
    void DrawPosition(int x, int y) { drawX = x; drawY = y; };
};