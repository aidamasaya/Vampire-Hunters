#include "stdafx.h"
#include "EnemyCalc.h"

EnemyCalc::EnemyCalc(std::shared_ptr<IGameObject> enemy) {
	_enemy = enemy;
}

float EnemyCalc::Damage(float attack, float hp) {
	auto damage = attack - hp;
	return damage;
}
/// <summary>
/// �v���C���[��ǂ�������
/// </summary>
/// <param name="speed">�G�̑���</param>
/// <param name="player">�v���C���[</param>
void EnemyCalc::Move(float speed, std::shared_ptr<IGameObject> player) {
	auto p = player;
	double angle = atan2(p->Transform.Position.Y - _enemy->Transform.Position.Y,
		p->Transform.Position.X - _enemy->Transform.Position.X);
	_enemy->Transform.Position.X += cos(angle) * speed * 0.15;
	_enemy->Transform.Position.Y += sin(angle) * speed * 0.15;
}

/// <summary>
/// �G�Ƌ������Ƃ�
/// </summary>
/// <param name="enemy">��������̓G</param>
void EnemyCalc::Distance(std::shared_ptr<IGameObject> enemy) {
	auto e = enemy;
	float distance = 20;
	float disX = enemy->Transform.Position.X - _enemy->Transform.Position.X + 10;
	float disY = enemy->Transform.Position.Y - _enemy->Transform.Position.Y + 10;
	float d = enemy->Transform.Size.Radius + _enemy->Transform.Size.Radius;
	if (sqrtf(disX * disX + disY + disY) <= d) {
		enemy->Transform.Position.X -= (_enemy->Transform.Size.X / 2 + enemy->Transform.Size.X / 2) * 0.5;
		enemy->Transform.Position.Y -= (_enemy->Transform.Size.Y / 2 + enemy->Transform.Size.Y / 2) * 0.5;
	}
}

/// <summary>
/// �m�b�N�o�b�N
/// </summary>
/// <param name="skill">�v���C���[�̕���</param>
void EnemyCalc::KnockBack(std::shared_ptr<IGameObject> skill) {
	float x = _enemy->Transform.Position.X - skill->Transform.Position.X;
	float y = _enemy->Transform.Position.Y - skill->Transform.Position.Y;
	float length = sqrtf(x * x + y * y);
	x = x / length * 50.0f;
	y = y / length * 50.0f;

	x *= 0.9f;
	y *= 0.9f;
	_enemy->Transform.Position.X += x;
	_enemy->Transform.Position.Y += y;
}