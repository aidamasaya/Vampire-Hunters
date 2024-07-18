#pragma once

#include "IWeapon.h"
#include "PlayerController.h"
#include "GarlicLevel.h"

//ニンニクを制御するクラス
class IWeapon;
class Garlic : public IWeapon {
	bool _draw = false;
	std::unique_ptr<GarlicLevel> _data;
public:
	Garlic();
	virtual ~Garlic() {};

	void Start();
	void Update(std::shared_ptr<IGameObject> player);
	void Draw();

	bool Hit_Callback(std::shared_ptr<Collider>);

	bool CoolDown();
	void LevelUp();
};