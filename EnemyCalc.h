#pragma once

#include "Enemy.h"
/// <summary>
/// 敵の動きを計算処理するクラス
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