#pragma once

#include "stdafx.h"
#include "EnemyCalc.h"

class ItemManager;
class EnemyCalc;
class Enemy : public IGameObject {
protected:
	int _img;
	float _hp;
	float _power;
	float _speed;
	bool _flag = false; //アクティブフラグ
	Vector2 _dir;

	//参照変数
	std::shared_ptr<EnemyCalc> _calc;
	std::shared_ptr<IGameObject> _player;
	std::weak_ptr<ItemManager> _manager;
public:
	Enemy();
	virtual ~Enemy() {};

	void Set_Player(std::shared_ptr<IGameObject> player) { _player = player; }
	void Set_ItemManager(std::shared_ptr<ItemManager> manager) { _manager = manager; }

	bool Hit_Callback(std::shared_ptr<Collider> target);

	Vector2 Get_Dir() { return _dir; }

	void Start(int);
	void Update();
	void Draw();
	void Drop();
	void Release();

	void Set_Flag(bool flag) { _flag = flag; }
	bool Get_Flag() { return _flag; }

	void Set_Speed(float speed) { _speed = speed; }
	void Set_Hp(float hp) { _hp = hp; }
	void Set_Power(float power) { _power = power; }
	float Get_Speed() const { return _speed; }
	float Get_HP() const { return _hp; }
	float Get_Power() const { return _power; }
};