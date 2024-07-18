#include "stdafx.h"
#include "GarlicLevel.h"

//レベル別上昇値データ
GarlicLevel::GarlicLevel() {
	_garlic[2]._power = 2;
	_garlic[2]._speed = 0;
	_garlic[2]._cooldown = 0;
	_garlic[2]._range = 0.4;
	_garlic[2]._timer = 0;

	_garlic[3]._power = 1;
	_garlic[3]._speed = 0;
	_garlic[3]._cooldown = 0.1;
	_garlic[3]._range = 0;
	_garlic[3]._timer = 0;

	_garlic[4]._power = 1;
	_garlic[4]._speed = 0;
	_garlic[4]._cooldown = 0;
	_garlic[4]._range = 0.2;
	_garlic[4]._timer = 0;

	_garlic[5]._power = 2;
	_garlic[5]._speed = 0;
	_garlic[5]._cooldown = 0.1;
	_garlic[5]._range = 0;
	_garlic[5]._timer = 0;

	_garlic[6]._power = 1;
	_garlic[6]._speed = 0;
	_garlic[6]._cooldown = 0.2;
	_garlic[6]._range = 0;
	_garlic[6]._timer = 0;

	_garlic[7]._power = 1;
	_garlic[7]._speed = 0;
	_garlic[7]._cooldown = 0.1;
	_garlic[7]._range = 0;
	_garlic[7]._timer = 0;

	_garlic[8]._power = 2;
	_garlic[8]._speed = 0;
	_garlic[8]._cooldown = 0.2;
	_garlic[8]._range = 0;
	_garlic[8]._timer = 0;
}
