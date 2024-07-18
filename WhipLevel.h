#pragma once

//上昇値構造体
typedef struct {
	bool _add;
	float _power;
	float _speed;
	float _cooldown;
	float _range;
	float _timer;
}whipdata_t;

class WhipLevel {
	whipdata_t _whip[9]; //上昇値配列
public:
	WhipLevel();
	virtual ~WhipLevel() {};
	//レベルに応じた上昇値データを渡す
	constexpr whipdata_t Get_Data(int level) { return _whip[level]; }
};