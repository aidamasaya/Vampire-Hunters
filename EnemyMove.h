#pragma once

#include "IPause.h"
#include "IScroll.h"
#include "EnemyPool.h"
#include "Reaper.h"

/// <summary>
/// �G���ꊇ�Ǘ�����N���X�B�I�u�W�F�N�g�v�[�����̗p���Ă���
/// </summary>
class EnemyMove : public IPause, public IScroll {
	bool _flag = false;
	std::shared_ptr<EnemyPool> enemy_Pool; //�G�̃I�u�W�F�N�g�v�[��
	std::shared_ptr<Reaper> _reaper;

	//�Q�ƕϐ�
	std::shared_ptr<IGameObject> _player;
	std::shared_ptr<ItemManager> _manager;
public:
	EnemyMove(std::shared_ptr<IGameObject>, std::shared_ptr<ItemManager>);
	virtual ~EnemyMove() {};

	void SetUp_Enemy(int, int);
	void Run();
	void Clean();
	void Death();

	Vector2 Random_SetPos();

	void Move_All() { _flag = true; }
	void Stop_All() { _flag = false; }

	void Scroll();
};