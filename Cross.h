#pragma once

#include "IWeapon.h"
#include "CrossLevel.h"

//\š‰Ë‚ğ§Œä‚·‚éƒNƒ‰ƒX
class Cross : public IWeapon {
	float x, y;
	float _speed;
	bool _draw = false;
	std::vector<std::shared_ptr<Cross>> _children;
	std::unique_ptr<CrossLevel> _data;
	void Reset(std::shared_ptr<IGameObject> player);
public:
	Cross();
	Cross(weapon_data, int);
	virtual ~Cross() {};

	void Start();
	void Update(std::shared_ptr<IGameObject>);
	void Draw();
	void Children(std::shared_ptr<IGameObject>);
	bool CoolDown();
	void Set_Dir(Vector2 dir) { Dir = dir; }

	bool Hit_Callback(std::shared_ptr<Collider>);

	void LevelUp();
	void Add_Weapon(std::shared_ptr<Cross> ball) { _children.push_back(ball); }
	std::vector<std::shared_ptr<Cross>> Get_Child() { return _children; }
};