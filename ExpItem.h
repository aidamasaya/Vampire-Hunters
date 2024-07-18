#pragma once

#include "Exp.h"
#include "BaseItem.h"
#include "PlayerLevel.h"

//�o���l�A�C�e���𐧌䂷��N���X
class PlayerLevel;
class Exp;
class ExpItem : public BaseItem {
	int _img;
	Exp* item_Exp; //�l��exp
public:
	ExpItem();
	virtual ~ExpItem() {};

	bool Hit_Callback(std::shared_ptr<Collider>);

	void SetUp(Transform2D);
	void Update();
	void Draw();

	void Action();
};