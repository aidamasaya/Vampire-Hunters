#pragma once

#include "IScroll.h"
#include "IPause.h"
#include "CoinItem.h"
#include "ItemManager.h"

//回復Orコインアイテムが入っているオブジェクト
class Interia : public IGameObject, public IPause, public IScroll {
	bool _flag;
	bool _active;
	int _img;
	std::shared_ptr<ItemManager> _manager; //参照変数
public:
	Interia(std::shared_ptr<ItemManager>);
	virtual ~Interia() {};

	void Setup();
	void Draw();

	bool Hit_Callback(std::shared_ptr<Collider>);

	void Scroll();

	void Stop_All() { _flag = false; }
	void Move_All() { _flag = true; }
};