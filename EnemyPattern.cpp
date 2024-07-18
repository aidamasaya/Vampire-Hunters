#include "stdafx.h"
#include "EnemyPattern.h"

EnemyPattern::EnemyPattern(std::shared_ptr<EnemyMove> move) {
	_move = move;
	cnt = 0;
	minute = 0;
	frame = 0;
	second = 0;
	_flag = true;
	i = 0;
}

void EnemyPattern::Main() {
	if (_flag == false) return;
		Update();
	Time();
}

void EnemyPattern::Update() {
	if (i == 7) return;
	auto m = _move.lock();
	if (appear[i] < second) {
		cnt = 0;
		second = 0;
		m->SetUp_Enemy(id[i], num[i]);
		i++;
	}
}

void EnemyPattern::Clean() {
	auto m = _move.lock();
	m->Clean();
}

void EnemyPattern::Death() {
	auto m = _move.lock();
	m->Death();
}

void EnemyPattern::Time() {
	if (i == 7) return;
	cnt++;
	second = cnt / 60;
}