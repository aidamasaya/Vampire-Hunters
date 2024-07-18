#include "stdafx.h"
#include "ItemManager.h"
#include "keyboard.h"

//�A�C�e���v�[���ł��炩���߃C���X�^���X���i�[
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

//�S�A�C�e�����A�N�e�B�u��
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

// �o���l�A�C�e����n��
void ItemManager::SetUp_Exp(Transform2D pos) {
	auto item = item_Pool->Recycle("Exp");
	item->SetUp(pos);
	item->Player_Exp(_exp);
}
// �R�C���A�C�e����n��
void ItemManager::SetUp_Coin(Transform2D pos) {
	auto item = item_Pool->Recycle("Coin");
	item->SetUp(pos);
}
// �񕜃A�C�e����n��
void ItemManager::SetUp_Heal(Transform2D pos) {
	auto item = item_Pool->Recycle("Heal");
	item->SetUp(pos);
}

//�R�X�N���[��
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