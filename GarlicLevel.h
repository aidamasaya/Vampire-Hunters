#pragma once

typedef struct {
	float _power;
	float _speed;
	float _cooldown;
	float _range;
	float _timer;
}garlicdata_t;


class GarlicLevel {
	garlicdata_t _garlic[9];
public:
	GarlicLevel();
	virtual ~GarlicLevel() {};
	constexpr garlicdata_t Get_Data(int level) { return _garlic[level]; }
};