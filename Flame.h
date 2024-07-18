#pragma once

#include "IWeapon.h"
#include "PlayerAttack.h"
#include "PlayerController.h"
#include "FlameLevel.h"

//‰Š‚Ìñ‚ğ§Œä‚·‚éƒNƒ‰ƒX
class Flame : public IWeapon {
	float x, y;
	void Move();
	std::unique_ptr<FlameLevel> _data;
	std::vector<std::shared_ptr<Flame>> _children;
public:
	Flame();
	Flame(weapon_data, int);
	virtual ~Flame() {};

	void Start();
	void Update(std::shared_ptr<IGameObject>);
	void Draw();
	void Children(std::shared_ptr<IGameObject> player);

	bool Hit_Callback(std::shared_ptr<Collider>);

	bool CoolDown();
	void LevelUp();
};