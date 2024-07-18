#include "stdafx.h"
#include "PotionLevel.h"
#include "SkillData.h"

//レベル別上昇値データ
PotionLevel::PotionLevel() {
	_potion[2]._power = 0;
	_potion[2]._speed = 0;
	_potion[2]._cooldown = 0;
	_potion[2]._range = 0.2;
	_potion[2]._timer = 0;

	_potion[3]._add = true;
	_potion[3]._power = 5;
	_potion[3]._speed = 0;
	_potion[3]._cooldown = 0;
	_potion[3]._range = 0;
	_potion[3]._timer = 0;

	_potion[4]._power = 0;
	_potion[4]._speed = 0;
	_potion[4]._cooldown = 0;
	_potion[4]._range = 0.2;
	_potion[4]._timer = 0;

	_potion[5]._add = true;
	_potion[5]._power = 10;
	_potion[5]._speed = 0;
	_potion[5]._cooldown = 0;
	_potion[5]._range = 0;
	_potion[5]._timer = 0.3;

	_potion[6]._power = 0;
	_potion[6]._speed = 0;
	_potion[6]._cooldown = 0;
	_potion[6]._range = 0.2;
	_potion[6]._timer = 0;

	_potion[7]._add = true;
	_potion[7]._power = 5;
	_potion[7]._speed = 0;
	_potion[7]._cooldown = 0;
	_potion[7]._range = 0;
	_potion[7]._timer = 0.3;

	_potion[8]._power = 5;
	_potion[8]._speed = 0;
	_potion[8]._cooldown = 0;
	_potion[8]._range = 0.2;
	_potion[8]._timer = 0;
}