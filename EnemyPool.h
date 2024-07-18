#pragma once

#include "Enemy.h"
#include <list>

/// <summary>
/// �ȈՃI�u�W�F�N�g�v�[���B�������[������������āA�������x�����肳����
/// </summary>
class EnemyPool {
	static const int POOL_SIZE = 500;
	std::list<std::shared_ptr<Enemy>> _enemies;
public:
	EnemyPool() {};
	virtual ~EnemyPool() {};

	//�G��size�C���X�^���X�����v�[���Ɋi�[
	void Enemy_Create(int size) {
		if (size > POOL_SIZE) return;

		for (int i = 0; i < size; i++) {
			_enemies.push_back(std::make_shared<Enemy>());
		}
	}

	//�G�̃C���X�^���X��Ԃ�
	std::shared_ptr<Enemy> Recycle() {
		for (auto enemy : _enemies) {
			if (enemy->Get_Flag() == false) {
				enemy->Set_Flag(true);
				return enemy;
			}
		}
		return nullptr;
	}

	//�G�l�~�[�v�[����Ԃ�
	std::list<std::shared_ptr<Enemy>> Get_Pool() {
		return _enemies;
	}

	//�A�N�e�B�u�ȓG�̂ݏ�����Update����
	void Update() {
		for (auto enemy : _enemies) {
			if (enemy->Get_Flag() == true) {
				enemy->Update();
			}
		}
	}

	//�A�N�e�B�u�ȓG�̂ݏ�����Draw����
	void Draw() {
		for (auto enemy : _enemies) {
			if (enemy->Get_Flag() == true) {
				enemy->Draw();
			}
		}
	}

	//�A�N�e�B�u�ȓG�̑�����Ԃ�
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