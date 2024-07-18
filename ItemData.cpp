#include "stdafx.h"
#include "ItemData.h"
#include "Macro.h"

static std::unique_ptr<ItemData> _instance;
ItemData* Get_ItemData_Instance()
{
	return _instance.get();
}

void ItemData::Set_up() {
	Get_ItemData_Instance()->itemdata[0]._id = 1;
	Get_ItemData_Instance()->itemdata[0]._img = LoadGraph("C:/Users/mynhj/Downloads/coin.png");
	Get_ItemData_Instance()->itemdata[0]._name = "Coin";
	Get_ItemData_Instance()->itemdata[1]._id = 2;
	Get_ItemData_Instance()->itemdata[1]._img = LoadGraph("C:/Users/mynhj/Downloads/kouseki.png");
	Get_ItemData_Instance()->itemdata[1]._name = "Exp";
	Get_ItemData_Instance()->itemdata[2]._id = 3;
	Get_ItemData_Instance()->itemdata[2]._img = LoadGraph("C:/Users/mynhj/Downloads/manga-niku.png");
	Get_ItemData_Instance()->itemdata[2]._name = "Heal";
}

itemdata_t ItemData::Get_Data(int num) {
	if (num > 2) {
		ERR("•s³‚È”’l‚Å‚·B");
	}
	else {
		return Get_ItemData_Instance()->itemdata[num];
	}
}

void ItemData::Create()
{
	if (_instance == nullptr)
	{
		_instance = std::unique_ptr<ItemData>(new ItemData());
	}
}

void ItemData::Release()
{
	_instance.release();
}