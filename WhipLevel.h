#pragma once

//�㏸�l�\����
typedef struct {
	bool _add;
	float _power;
	float _speed;
	float _cooldown;
	float _range;
	float _timer;
}whipdata_t;

class WhipLevel {
	whipdata_t _whip[9]; //�㏸�l�z��
public:
	WhipLevel();
	virtual ~WhipLevel() {};
	//���x���ɉ������㏸�l�f�[�^��n��
	constexpr whipdata_t Get_Data(int level) { return _whip[level]; }
};