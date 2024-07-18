#include "stdafx.h"
#include "SkillData.h"
#include "Macro.h"

static std::unique_ptr<SkillData> _instance;
SkillData* Get_SkillData_Instance() {
	return _instance.get();
}


void SkillData::Set_up() {
	Get_SkillData_Instance()->skilldata[0]._id = 1;
	Get_SkillData_Instance()->skilldata[0]._power = 10;
	Get_SkillData_Instance()->skilldata[0]._speed = 5;
	Get_SkillData_Instance()->skilldata[0]._cooldown = 3;
	Get_SkillData_Instance()->skilldata[0]._range = 0.3;
	Get_SkillData_Instance()->skilldata[0]._timer = 0.5;
	Get_SkillData_Instance()->skilldata[0].penetration = true;
	Get_SkillData_Instance()->skilldata[0]._img[0] = LoadGraph("C:/Users/mynhj/Downloads/EffectWhip.png");
	Get_SkillData_Instance()->skilldata[0].img_handle = "C:/Users/mynhj/Downloads/EffectWhip.png";
	Get_SkillData_Instance()->skilldata[0]._name = "鞭";
	Get_SkillData_Instance()->skilldata[0]._description = "横方向に攻撃を繰り出す。";

	Get_SkillData_Instance()->skilldata[1]._id = 2;
	Get_SkillData_Instance()->skilldata[1]._power = 5;
	Get_SkillData_Instance()->skilldata[1]._speed = 5;
	Get_SkillData_Instance()->skilldata[1]._cooldown = 3;
	Get_SkillData_Instance()->skilldata[1]._range = 0.3;
	Get_SkillData_Instance()->skilldata[1]._timer = 9;
	Get_SkillData_Instance()->skilldata[1].penetration = true;
	Get_SkillData_Instance()->skilldata[1]._img[0] = LoadGraph("C:/Users/mynhj/Downloads/Potion.png");
	Get_SkillData_Instance()->skilldata[1].img_handle = "C:/Users/mynhj/Downloads/Potion.png";
	Get_SkillData_Instance()->skilldata[1]._img[1] = LoadGraph("C:/Users/mynhj/Downloads/download (2).png");
	Get_SkillData_Instance()->skilldata[1]._name = "聖水";
	Get_SkillData_Instance()->skilldata[1]._description = "ダメージゾーンを生成する。";

	Get_SkillData_Instance()->skilldata[2]._id = 3;
	Get_SkillData_Instance()->skilldata[2]._power = 20;
	Get_SkillData_Instance()->skilldata[2]._speed = 5;
	Get_SkillData_Instance()->skilldata[2]._cooldown = 0.5;
	Get_SkillData_Instance()->skilldata[2]._range = 0.3;
	Get_SkillData_Instance()->skilldata[2]._timer = 10;
	Get_SkillData_Instance()->skilldata[2].penetration = false;
	Get_SkillData_Instance()->skilldata[2]._img[0] = LoadGraph("C:/Users/mynhj/Downloads/ShotFlame.png");
	Get_SkillData_Instance()->skilldata[2].img_handle = "C:/Users/mynhj/Downloads/ShotFlame.png";
	Get_SkillData_Instance()->skilldata[2]._name = "炎の杖";
	Get_SkillData_Instance()->skilldata[2]._description = "大ダメージ。\n狙う敵はランダムに決定。";

	Get_SkillData_Instance()->skilldata[3]._id = 4;
	Get_SkillData_Instance()->skilldata[3]._power = 10;
	Get_SkillData_Instance()->skilldata[3]._speed = 5;
	Get_SkillData_Instance()->skilldata[3]._cooldown = 3;
	Get_SkillData_Instance()->skilldata[3]._range = 0.5;
	Get_SkillData_Instance()->skilldata[3]._timer = 10;
	Get_SkillData_Instance()->skilldata[3].penetration = true;
	Get_SkillData_Instance()->skilldata[3]._img[0] = LoadGraph("C:/Users/mynhj/Downloads/Garlic.png");
	Get_SkillData_Instance()->skilldata[3].img_handle = "C:/Users/mynhj/Downloads/Garlic.png";
	Get_SkillData_Instance()->skilldata[3]._name = "ニンニク";
	Get_SkillData_Instance()->skilldata[3]._description = "近くの敵にダメージを与える。";

	Get_SkillData_Instance()->skilldata[4]._id = 5;
	Get_SkillData_Instance()->skilldata[4]._power = 10;
	Get_SkillData_Instance()->skilldata[4]._speed = 5;
	Get_SkillData_Instance()->skilldata[4]._cooldown = 3;
	Get_SkillData_Instance()->skilldata[4]._range = 0.2;
	Get_SkillData_Instance()->skilldata[4]._timer = 10;
	Get_SkillData_Instance()->skilldata[4].penetration = true;
	Get_SkillData_Instance()->skilldata[4]._img[0] = LoadGraph("C:/Users/mynhj/source/repos/testc++/Sprite-0001.png");
	Get_SkillData_Instance()->skilldata[4].img_handle = "C:/Users/mynhj/source/repos/testc++/Sprite-0001.png";
	Get_SkillData_Instance()->skilldata[4]._name = "軌跡の魔弾";
	Get_SkillData_Instance()->skilldata[4]._description = "跳ね返りながら敵を通り抜ける。";

	Get_SkillData_Instance()->skilldata[5]._id = 6;
	Get_SkillData_Instance()->skilldata[5]._power = 10;
	Get_SkillData_Instance()->skilldata[5]._speed = 6;
	Get_SkillData_Instance()->skilldata[5]._cooldown = 3;
	Get_SkillData_Instance()->skilldata[5]._range = 0.2;
	Get_SkillData_Instance()->skilldata[5]._timer = 10;
	Get_SkillData_Instance()->skilldata[5].penetration = true;
	Get_SkillData_Instance()->skilldata[5]._img[0] = LoadGraph("C:/Users/mynhj/source/repos/testc++/Cross.png");
	Get_SkillData_Instance()->skilldata[5].img_handle = "C:/Users/mynhj/source/repos/testc++/Cross.png";
	Get_SkillData_Instance()->skilldata[5]._name = "十字架";
	Get_SkillData_Instance()->skilldata[5]._description = "最も近い敵めがけて発射。\nブーメランのように機能する。";
}

skilldata_t SkillData::Get_Data(int num) {
	if (num > 5) {
		ERR("不正な数値です。");
	}
	else {
		return Get_SkillData_Instance()->skilldata[num];
	}
}

void SkillData::Create()
{
	if (_instance == nullptr)
	{
		_instance = std::unique_ptr<SkillData>(new SkillData());
	}
}

void SkillData::Release()
{
	_instance.release();
}