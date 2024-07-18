#pragma once

typedef struct {
	bool _add;
	float _power;
	float _speed;
	float _cooldown;
	float _range;
	float _timer;
}crossdata_t;

class CrossLevel {
	crossdata_t _cross[9];
public:
	CrossLevel();
	virtual ~CrossLevel() {};
	crossdata_t Get_Data(int level) { return _cross[level]; }
};