#pragma once

#include "stdafx.h"
#include "BaseItem.h"
#include "CoinItem.h"
#include "ExpItem.h"
#include "HealItem.h"
#include <list>

//アイテムプール関数の中身はエネミープールとほぼ同じ
class ItemPool {
	static const int POOL_SIZE = 800;
	std::map<const char*, std::list<std::shared_ptr<BaseItem>>> _items;
public:
	ItemPool() {};
	virtual ~ItemPool() {};

	void Coin_Create(int size, const char* name) {
		if (size > POOL_SIZE) return;

		for (int i = 0; i < size; i++) {
			_items[name].push_back(std::make_shared<CoinItem>());
		}
	}

	void Exp_Create(int size, const char* name) {
		if (size > POOL_SIZE) return;

		for (int i = 0; i < size; i++) {
			_items[name].push_back(std::make_shared<ExpItem>());
		}
	}

	void Heal_Create(int size, const char* name) {
		if (size > POOL_SIZE) return;

		for (int i = 0; i < size; i++) {
			_items[name].push_back(std::make_shared<HealItem>());
		}
	}

	std::shared_ptr<BaseItem> Recycle(const char* name) {
		for (auto item : _items[name]) {
			if (item->Get_Flag() == false) {
				item->Set_Flag(true);
				return item;
			}
		}
		return nullptr;
	}

	std::map<const char*, std::list<std::shared_ptr<BaseItem>>> Get_Object() {
		return _items;
	}


	void Update() {
		for (auto itr = _items.begin(); itr != _items.end(); ++itr) {
			for (auto item : itr->second) {
				if (item->Get_Flag() == true) {
					item->Update();
				}
			}
		}
	}

	void Draw() {
		for (auto itr = _items.begin(); itr != _items.end(); ++itr) {
			for (auto item : itr->second) {
				if (item->Get_Flag() == true) {
					item->Draw();
				}
			}
		}
	}

	int Count() {
		int cnt = 0;
		for (auto itr = _items.begin(); itr != _items.end(); ++itr) {
			for (auto item : itr->second) {
				if (item->Get_Flag() == true) {
					cnt++;
				}
			}
		}
		return cnt;
	}
};