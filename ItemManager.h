#pragma once

#include "IScroll.h"
#include "ItemPool.h"
#include "ItemData.h"

//アイテム管理クラスリクエストに応じたアイテムを提供する
class ItemManager : public IPause, public IScroll {
	bool _flag;
	std::shared_ptr<ItemPool> item_Pool; //アイテムプール
	std::shared_ptr<ExpAdministrator> _exp; //参照変数

	std::vector<std::shared_ptr<BaseItem>> Items;//スクロールさせるアイテムを格納
public:
	ItemManager();
	virtual ~ItemManager() {};

	void Set_Admini(std::shared_ptr<ExpAdministrator> exp) { _exp = exp; }

	void SetUp_Exp(Transform2D pos);
	void SetUp_Coin(Transform2D pos);
	void SetUp_Heal(Transform2D pos);

	void Run();
	void Erase();

	void Move_All() { _flag = true; }
	void Stop_All() { _flag = false; }

	void Scroll();
};