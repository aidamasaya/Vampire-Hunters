#include "stdafx.h"
#include "EnemyData.h"
#include "Macro.h"

static std::unique_ptr<EnemyData> _instance;
EnemyData* Get_EnemyData_Instance()
{
	return _instance.get();
}

void EnemyData::Set_up() {
	Get_EnemyData_Instance()->enemydata[0]._id = 1;
	Get_EnemyData_Instance()->enemydata[0]._img = LoadGraph("C:/Users/mynhj/Downloads/スカウト展　提出データ/Image/Skelton.png");
	Get_EnemyData_Instance()->enemydata[0]._name = "NormalCreature";
	Get_EnemyData_Instance()->enemydata[0]._atk = 8;
	Get_EnemyData_Instance()->enemydata[0]._def = 3;
	Get_EnemyData_Instance()->enemydata[0]._hp = 10;
	Get_EnemyData_Instance()->enemydata[0]._speed = 2;

	Get_EnemyData_Instance()->enemydata[1]._id = 2;
	Get_EnemyData_Instance()->enemydata[1]._img = LoadGraph("C:/Users/mynhj/Downloads/スカウト展　提出データ/Image/WareWolf.png");
	Get_EnemyData_Instance()->enemydata[1]._name = "BigCreature";
	Get_EnemyData_Instance()->enemydata[1]._atk = 10;
	Get_EnemyData_Instance()->enemydata[1]._def = 5;
	Get_EnemyData_Instance()->enemydata[1]._hp = 20;
	Get_EnemyData_Instance()->enemydata[1]._speed = 5;

	Get_EnemyData_Instance()->enemydata[2]._id = 3;
	Get_EnemyData_Instance()->enemydata[2]._img = LoadGraph("C:/Users/mynhj/Downloads/Bat.png");
	Get_EnemyData_Instance()->enemydata[2]._name = "SmallCreature";
	Get_EnemyData_Instance()->enemydata[2]._atk = 5;
	Get_EnemyData_Instance()->enemydata[2]._def = 1;
	Get_EnemyData_Instance()->enemydata[2]._hp = 5;
	Get_EnemyData_Instance()->enemydata[2]._speed = 2;

	Get_EnemyData_Instance()->enemydata[3]._id = 4;
	Get_EnemyData_Instance()->enemydata[3]._img = LoadGraph("C:/Users/mynhj/source/repos/testc++/Reaper.png");
	Get_EnemyData_Instance()->enemydata[3]._name = "Reaper";
	Get_EnemyData_Instance()->enemydata[3]._atk = 10;
	Get_EnemyData_Instance()->enemydata[3]._def = 1;
	Get_EnemyData_Instance()->enemydata[3]._hp = 999;
	Get_EnemyData_Instance()->enemydata[3]._speed = 30;
}

enemydata_t EnemyData::Get_Data(int num) {
	if (num > 3) {
		ERR("不正な数値です。");
	}
	else {
		return Get_EnemyData_Instance()->enemydata[num];
	}
}

void EnemyData::Create()
{
	if (_instance == nullptr)
	{
		_instance = std::unique_ptr<EnemyData>(new EnemyData());
	}
}

void EnemyData::Release()
{
	_instance.release();
}