#include "stdafx.h"
#include "WhipLevel.h"
#include "SkillData.h"

//レベル別上昇値データ
WhipLevel::WhipLevel() {
	_whip[2]._add = true;
	_whip[2]._power = 0;
	_whip[2]._speed = 0;
	_whip[2]._cooldown = 0;
	_whip[2]._range = 0;
	_whip[2]._timer = 0;

	_whip[3]._power = 5;
	_whip[3]._speed = 0;
	_whip[3]._cooldown = 0;
	_whip[3]._range = 0;
	_whip[3]._timer = 0;

	_whip[4]._power = 5;
	_whip[4]._speed = 0;
	_whip[4]._cooldown = 0;
	_whip[4]._range = 0.1;
	_whip[4]._timer = 0;

	_whip[5]._power = 5;
	_whip[5]._speed = 0;
	_whip[5]._cooldown = 0;
	_whip[5]._range = 0;
	_whip[5]._timer = 0;

	_whip[6]._power = 5;
	_whip[6]._speed = 0;
	_whip[6]._cooldown = 0;
	_whip[6]._range = 0.1;
	_whip[6]._timer = 0;

	_whip[7]._power = 5;
	_whip[7]._speed = 0;
	_whip[7]._cooldown = 0;
	_whip[7]._range = 0;
	_whip[7]._timer = 0;

	_whip[8]._power = 5;
	_whip[8]._speed = 0;
	_whip[8]._cooldown = 0;
	_whip[8]._range = 0;
	_whip[8]._timer = 0;
}