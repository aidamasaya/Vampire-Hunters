#pragma once

#include "EnemyMove.h"
#include "IPause.h"

class EnemyPattern : public IPause{
	bool _flag;
	int i;
	int cnt;
	int minute;
	int frame;
	int second;

	std::weak_ptr<EnemyMove> _move;
	//エネミー出現データ
	int appear[7] = { 3,7,10,10,10,10,10 }; //指定時間
	int id[7] = { 0,1,2,1,0,2,1 }; //種類
	int num[7] = { 10,30,30,35,35,50,200 }; //個数

	void Update();
	void Time();
public:
	EnemyPattern(std::shared_ptr<EnemyMove>);
	virtual ~EnemyPattern() {};

	void Main();
	void Clean();
	void Death();

	void Stop_All() { _flag = false; }
	void Move_All() { _flag = true; }
};