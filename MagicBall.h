#pragma once

#include "IWeapon.h"
#include "MagicBallLevel.h"

//‹OÕ‚Ì–‚’e‚ğ§Œä‚·‚éƒNƒ‰ƒX
class MagicBall : public IWeapon {
	float x, y;
	bool _draw = false;
	std::vector<std::shared_ptr<MagicBall>> _children;
	std::unique_ptr<MagicBallLevel> _data;
	void Reset(std::shared_ptr<IGameObject>);
	void Bound();
public:
	MagicBall();
	MagicBall(weapon_data data, int level);
	virtual ~MagicBall() {};

	void Start();
	void Update(std::shared_ptr<IGameObject>);
	void Draw();
	void Children(std::shared_ptr<IGameObject>);
	bool CoolDown();
	void Set_Dir(Vector2 dir) { Dir = dir; }

	bool Hit_Callback(std::shared_ptr<Collider>);

	void LevelUp();
	void Add_Weapon(std::shared_ptr<MagicBall> ball) { _children.push_back(ball); }
	std::vector<std::shared_ptr<MagicBall>> Get_Child() { return _children; }
};