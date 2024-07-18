#pragma once

typedef struct {
	bool _add;
	float _power;
	float _speed;
	float _cooldown;
	float _range;
	float _timer;
}potiondata_t;


class PotionLevel {
	potiondata_t _potion[9];
public:
	PotionLevel();
	virtual ~PotionLevel() {};
	constexpr potiondata_t Get_Data(int level) { return _potion[level]; }
};