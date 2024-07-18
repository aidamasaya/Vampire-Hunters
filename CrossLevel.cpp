#include "stdafx.h"
#include "CrossLevel.h"

//レベル別上昇値データ
CrossLevel::CrossLevel() {
	_cross[2]._power = 10;
	_cross[2]._speed = 0;
	_cross[2]._cooldown = 0;
	_cross[2]._range = 0;
	_cross[2]._timer = 0;

	_cross[3]._power = 0;
	_cross[3]._speed = 0.25;
	_cross[3]._cooldown = 0;
	_cross[3]._range = 0.1;
	_cross[3]._timer = 0;

	_cross[4]._add = true;
	_cross[4]._power = 0;
	_cross[4]._speed = 0;
	_cross[4]._cooldown = 0;
	_cross[4]._range = 0;
	_cross[4]._timer = 0;

	_cross[5]._power = 10;
	_cross[5]._speed = 0;
	_cross[5]._cooldown = 0;
	_cross[5]._range = 0;
	_cross[5]._timer = 0;

	_cross[6]._power = 0;
	_cross[6]._speed = 0.25;
	_cross[6]._cooldown = 0;
	_cross[6]._range = 0.1;
	_cross[6]._timer = 0;

	_cross[7]._add = true;
	_cross[7]._power = 0;
	_cross[7]._speed = 0;
	_cross[7]._cooldown = 0;
	_cross[7]._range = 0;
	_cross[7]._timer = 0;

	_cross[8]._power = 10;
	_cross[8]._speed = 0;
	_cross[8]._cooldown = 0;
	_cross[8]._range = 0;
	_cross[8]._timer = 0;
}