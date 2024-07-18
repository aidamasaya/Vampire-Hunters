#pragma once

typedef struct {
	bool _add;
	float _power;
	float _speed;
	float _cooldown;
	float _range;
	float _timer;
}flamedata_t;

class FlameLevel {
	flamedata_t _flame[9];
public:
	FlameLevel();
	virtual ~FlameLevel() {};
	flamedata_t Get_Data(int level) { return _flame[level]; }
};