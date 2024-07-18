#pragma once

#include "ExpAdministrator.h"
#include "PlayerController.h"

//アイテムの基底クラス
class BaseItem : public IGameObject {
protected:
	int _flag, cnt, knd, state;
	int _img;
	std::weak_ptr<ExpAdministrator> player_Exp;
public:
	BaseItem() {};
	virtual ~BaseItem() {};

	virtual void SetUp(Transform2D) {};
	virtual void Update() {};
	virtual void Draw() {}
	virtual void Action() {};
	void Erase() { Destroy(); }

	void Player_Exp(std::shared_ptr<ExpAdministrator> exp) { player_Exp = exp; }
	void Set_Flag(bool flag) { _flag = flag; }
	bool Get_Flag() { return _flag; }
};