#include "stdafx.h"
#include "ItemManager.h"
#include "keyboard.h"

//アイテムプールであらかじめインスタンスを格納
ItemManager::ItemManager() {
	_flag = true;
	item_Pool = std::make_shared<ItemPool>();
	item_Pool->Coin_Create(100, "Coin");
	item_Pool->Exp_Create(500, "Exp");
	item_Pool->Heal_Create(100, "Heal");
	auto items = item_Pool->Get_Object();
	for (auto itr = items.begin(); itr != items.end(); ++itr) {
		for (auto item : itr->second) {
			Items.push_back(item);
		}
	}
}

void ItemManager::Run() {
	if (item_Pool->Count() > 0) {
		if (_flag == true) {
			item_Pool->Update();
		}
		item_Pool->Draw();
	}
}

//全アイテムを非アクティブ化
void ItemManager::Erase() {
	auto items = item_Pool->Get_Object();
	for (auto itr = items.begin(); itr != items.end(); ++itr) {
		for (auto item : itr->second) {
			if (item->Get_Flag() == true) {
				item->Set_Flag(false);
				item->Erase();
			}
		}
	}
}

// 経験値アイテムを渡す
void ItemManager::SetUp_Exp(Transform2D pos) {
	auto item = item_Pool->Recycle("Exp");
	item->SetUp(pos);
	item->Player_Exp(_exp);
}
// コインアイテムを渡す
void ItemManager::SetUp_Coin(Transform2D pos) {
	auto item = item_Pool->Recycle("Coin");
	item->SetUp(pos);
}
// 回復アイテムを渡す
void ItemManager::SetUp_Heal(Transform2D pos) {
	auto item = item_Pool->Recycle("Heal");
	item->SetUp(pos);
}

//嘘スクロール
void ItemManager::Scroll() {
	if (_flag == false) return;

	for (auto item : Items) {
		if (Keyboard::getPressingCount(KEY_INPUT_LEFT) > 0) {
			item->Transform.Position.X += 2;
		}if (Keyboard::getPressingCount(KEY_INPUT_RIGHT) > 0) {
			item->Transform.Position.X -= 2;
		}if (Keyboard::getPressingCount(KEY_INPUT_DOWN) > 0) {
			item->Transform.Position.Y -= 2;
		}if (Keyboard::getPressingCount(KEY_INPUT_UP) > 0) {
			item->Transform.Position.Y += 2;
		}
	}
}