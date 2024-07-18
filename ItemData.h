#pragma once

#include "stdafx.h"

typedef struct {
public:
	int _id;
	int _img;
	const char* _name;
}itemdata_t;

class ItemData : Singleton<ItemData> {
public:
	itemdata_t itemdata[256];

	static void Set_up();
	static itemdata_t Get_Data(int);

	static void Create();
	static void Release();
};