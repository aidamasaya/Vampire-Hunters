#pragma once

#include "Enemy.h"
/// <summary>
/// �G�̓������v�Z��������N���X
/// </summary>
class EnemyCalc {
	std::shared_ptr<IGameObject> _enemy;
public:
	EnemyCalc(std::shared_ptr<IGameObject>);
	virtual ~EnemyCalc() {};
	float Damage(float, float);
	void Move(float, std::shared_ptr<IGameObject>);
	void Distance(std::shared_ptr<IGameObject>);
	void KnockBack(std::shared_ptr<IGameObject>);
};