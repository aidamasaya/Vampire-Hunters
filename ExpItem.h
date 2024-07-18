#pragma once

#include "Exp.h"
#include "BaseItem.h"
#include "PlayerLevel.h"

//経験値アイテムを制御するクラス
class PlayerLevel;
class Exp;
class ExpItem : public BaseItem {
	int _img;
	Exp* item_Exp; //獲得exp
public:
	ExpItem();
	virtual ~ExpItem() {};

	bool Hit_Callback(std::shared_ptr<Collider>);

	void SetUp(Transform2D);
	void Update();
	void Draw();

	void Action();
};