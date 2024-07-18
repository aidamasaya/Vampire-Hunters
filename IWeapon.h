#pragma once

#include "stdafx.h"
#include "IPause.h"

//����̊��N���X
class IWeapon : public IGameObject {
protected:
	const char* _name = ""; //����̖��O
	int _level = 0; //���탌�x��
	int _img = 0;
	//����\����
	typedef struct {
		float _power;
		float _speed;
		float _cooldown;
		float _range;
		float _timer;
	}weapon_data;

	//���Ԑ���
	int _frame = 0;
	int _sec = 0;
	int _counter = 0;
	float _cool = 0;

	bool _flag = false;
	weapon_data _status; //�\���̐錾
	std::weak_ptr<IGameObject> _player;//�Q�ƕϐ�
public:
	//�\���̂̏�����
	IWeapon() {
		_status._power = 0;
		_status._speed = 0;
		_status._cooldown = 0;
		_status._range = 0;
		_status._timer = 0;
	};
	virtual ~IWeapon() {};

	virtual void Start() {};
	virtual void Update(std::shared_ptr<IGameObject>) {};
	virtual void Draw() {};

	virtual bool CoolDown() { return false; }
	virtual void LevelUp() {};

	void Set_Player(std::shared_ptr<IGameObject> player) { _player = player; }
	bool Get_Flag() { return _flag; }
	void Set_Flag(bool flag) { _flag = flag; }

	constexpr int Current_Level() { return _level; }
	weapon_data Get_Data() { return _status; }
	virtual int Get_Img() { return _img; }
	const char* Get_Name() { return _name; }
	float Get_Power() { return _status._power; }
};