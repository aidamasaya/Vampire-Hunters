#include "stdafx.h"
#include "MagicBallLevel.h"

//レベル別上昇値データ
MagicBallLevel::MagicBallLevel() {
	_ball[2]._power = 5;
	_ball[2]._speed = 0.2;
	_ball[2]._cooldown = 0;
	_ball[2]._range = 0;
	_ball[2]._timer = 0;

	_ball[3]._power = 5;
	_ball[3]._speed = 0.2;
	_ball[3]._cooldown = 0;
	_ball[3]._range = 0;
	_ball[3]._timer = 0.3;

	_ball[4]._add = true;
	_ball[4]._power = 0;
	_ball[4]._speed = 0;
	_ball[4]._cooldown = 0;
	_ball[4]._range = 0;
	_ball[4]._timer = 0;

	_ball[5]._power = 5;
	_ball[5]._speed = 0.2;
	_ball[5]._cooldown = 0;
	_ball[5]._range = 0;
	_ball[5]._timer = 0;

	_ball[6]._add = true;
	_ball[6]._power = 5;
	_ball[6]._speed = 0;
	_ball[6]._cooldown = 0;
	_ball[6]._range = 0;
	_ball[6]._timer = 0.3;

	_ball[7]._add = true;
	_ball[7]._power = 0;
	_ball[7]._speed = 0;
	_ball[7]._cooldown = 0;
	_ball[7]._range = 0;
	_ball[7]._timer = 0;

	_ball[8]._power = 0;
	_ball[8]._speed = 0;
	_ball[8]._cooldown = 0;
	_ball[8]._range = 0;
	_ball[8]._timer = 0.5;
}