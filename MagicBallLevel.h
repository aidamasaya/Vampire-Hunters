#pragma once

typedef struct {
	bool _add;
	float _power;
	float _speed;
	float _cooldown;
	float _range;
	float _timer;
}magicballdata_t;


class MagicBallLevel {
	magicballdata_t _ball[9];
public:
	MagicBallLevel();
	virtual ~MagicBallLevel() {};
	constexpr magicballdata_t Get_Data(int level) { return _ball[level]; }
};