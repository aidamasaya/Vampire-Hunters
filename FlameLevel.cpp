#include "stdafx.h"
#include "FlameLevel.h"

//レベル別上昇値データ
FlameLevel::FlameLevel() {
	_flame[2]._power = 10;
	_flame[2]._speed = 0;
	_flame[2]._cooldown = 0;
	_flame[2]._range = 0;
	_flame[2]._timer = 0;

	_flame[3]._power = 10;
	_flame[3]._speed = 0.2;
	_flame[3]._cooldown = 0;
	_flame[3]._range = 0;
	_flame[3]._timer = 0;

	_flame[4]._power = 10;
	_flame[4]._speed = 0;
	_flame[4]._cooldown = 0;
	_flame[4]._range = 0;
	_flame[4]._timer = 0;

	_flame[5]._power = 10;
	_flame[5]._speed = 0.2;
	_flame[5]._cooldown = 0;
	_flame[5]._range = 0;
	_flame[5]._timer = 0;

	_flame[6]._power = 10;
	_flame[6]._speed = 0;
	_flame[6]._cooldown = 0;
	_flame[6]._range = 0;
	_flame[6]._timer = 0;

	_flame[7]._power = 10;
	_flame[7]._speed = 0.2;
	_flame[7]._cooldown = 0;
	_flame[7]._range = 0;
	_flame[7]._timer = 0;

	_flame[8]._power = 10;
	_flame[8]._speed = 0;
	_flame[8]._cooldown = 0;
	_flame[8]._range = 0;
	_flame[8]._timer = 0;
}