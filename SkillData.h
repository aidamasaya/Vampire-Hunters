#pragma once

#include "stdafx.h"

typedef struct {
	int _id;
	int _img[2];
	const char* img_handle;
	float _power;
	float _speed;
	float _cooldown;
	float _range;
	float _timer;
	const char* _name;
	const char* _description;
	bool penetration;
}skilldata_t;

class SkillData : public Singleton<SkillData> {
	SkillData() {};
	skilldata_t skilldata[6];
public:
	static void Set_up();
	static skilldata_t Get_Data(int);

	static void Create();
	static void Release();
};