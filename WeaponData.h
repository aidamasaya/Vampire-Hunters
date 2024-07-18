#pragma once

#include "SkillData.h"

/// <summary>
/// 武器データ表示クラス
/// </summary>
class WeaponData {
	int _img;
	int _level;
	const char* _name;
	const char* _des;
public:
	WeaponData(int id) {
		_img = SkillData::Get_Data(id)._img[0];
		_level = 1;
		_name = SkillData::Get_Data(id)._name;
		_des = SkillData::Get_Data(id)._description;
	};
	virtual ~WeaponData() {};

	void Add_Level() { _level++; }
	int Get_Img() { return _img; }
	int Get_Level() { return _level; }
	const char* Get_Name() { return _name; }
	const char* Get_Des() { return _des; }
};