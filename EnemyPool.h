#pragma once

#include "Enemy.h"
#include <list>

/// <summary>
/// 簡易オブジェクトプール。メモリー消費をおさえて、処理速度を安定させる
/// </summary>
class EnemyPool {
	static const int POOL_SIZE = 500;
	std::list<std::shared_ptr<Enemy>> _enemies;
public:
	EnemyPool() {};
	virtual ~EnemyPool() {};

	//敵をsize個インスタンス化しプールに格納
	void Enemy_Create(int size) {
		if (size > POOL_SIZE) return;

		for (int i = 0; i < size; i++) {
			_enemies.push_back(std::make_shared<Enemy>());
		}
	}

	//敵のインスタンスを返す
	std::shared_ptr<Enemy> Recycle() {
		for (auto enemy : _enemies) {
			if (enemy->Get_Flag() == false) {
				enemy->Set_Flag(true);
				return enemy;
			}
		}
		return nullptr;
	}

	//エネミープールを返す
	std::list<std::shared_ptr<Enemy>> Get_Pool() {
		return _enemies;
	}

	//アクティブな敵のみ処理をUpdateする
	void Update() {
		for (auto enemy : _enemies) {
			if (enemy->Get_Flag() == true) {
				enemy->Update();
			}
		}
	}

	//アクティブな敵のみ処理をDrawする
	void Draw() {
		for (auto enemy : _enemies) {
			if (enemy->Get_Flag() == true) {
				enemy->Draw();
			}
		}
	}

	//アクティブな敵の総数を返す
	int Count() {
		int cnt = 0;
		for (auto enemy : _enemies) {
			if (enemy->Get_Flag() == true) {
				cnt++;
			}
		}
		return cnt;
	}
};