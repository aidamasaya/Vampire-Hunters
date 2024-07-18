#pragma once

#include "IPause.h"
#include "IScroll.h"
#include "EnemyPool.h"
#include "Reaper.h"

/// <summary>
/// 敵を一括管理するクラス。オブジェクトプールを採用している
/// </summary>
class EnemyMove : public IPause, public IScroll {
	bool _flag = false;
	std::shared_ptr<EnemyPool> enemy_Pool; //敵のオブジェクトプール
	std::shared_ptr<Reaper> _reaper;

	//参照変数
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