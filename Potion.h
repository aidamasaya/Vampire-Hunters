#pragma once

#include "IWeapon.h"
#include "PlayerController.h"
#include "PotionLevel.h"

//�����𐧌䂷��N���X
class Potion : public IWeapon {
	int _img[2];
	float x, y;
	std::vector<std::shared_ptr<Potion>> _children; //�q�N���X
	std::unique_ptr<PotionLevel> _data; //����̏㏸�l�f�[�^
	void Move();
public:
	Potion();
	Potion(weapon_data, int);
	virtual ~Potion() {};

	void Start();
	void Update(std::shared_ptr<IGameObject>);
	void Draw();
	void Children(std::shared_ptr<IGameObject> player);

	bool Hit_Callback(std::shared_ptr<Collider>);

	int Get_Img() { return _img[0]; }
	bool CoolDown();
	void LevelUp();
};