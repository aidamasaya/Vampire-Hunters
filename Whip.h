#pragma once

#include "IWeapon.h"
#include "WhipLevel.h"

//�ڂ𐧌䂷��N���X
class Whip : public IWeapon {
	bool _draw = false;
	std::vector<std::shared_ptr<Whip>> _children; //�q�N���X
	std::unique_ptr<WhipLevel> _data; //����̏㏸�l�f�[�^
public:
	Whip();
	Whip(weapon_data, int);
	virtual ~Whip() {};

	void Start();
	void Update(std::shared_ptr<IGameObject>);
	void Draw();
	void Children(std::shared_ptr<IGameObject> player);
	bool CoolDown();
	void Set_Dir(Vector2 dir) { Dir = dir; }

	bool Hit_Callback(std::shared_ptr<Collider>);

	void LevelUp();
	void Add_Weapon(std::shared_ptr<Whip> whip) { _children.push_back(whip); }
	std::vector<std::shared_ptr<Whip>> Get_Child() { return _children; }
};