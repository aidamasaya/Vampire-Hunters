#pragma once

#include "stdafx.h"

typedef struct {
public:
	int _id;
	float _atk;
	float _def;
	float _speed;
	int _img;
	float _hp;
	const char* _name;
}enemydata_t;

class EnemyData : Singleton<EnemyData> {
public:
	enemydata_t enemydata[256];

	static void Set_up();
	static enemydata_t Get_Data(int);

	static void Create();
	static void Release();
};