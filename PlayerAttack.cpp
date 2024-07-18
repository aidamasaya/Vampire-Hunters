#include "stdafx.h"
#include "PlayerAttack.h"

PlayerAttack::PlayerAttack() {
	_flag = true;
}
//プレイヤーのポインタを受け取る
void PlayerAttack::Start(std::shared_ptr<IGameObject> player) {
	_player = player;
}

//持っている武器のメソッドをまとめて呼び出す
void PlayerAttack::Update() {
	if (_flag == false) return;

	for (auto weapon : _weapons) {
		if (weapon.second != nullptr) {
			weapon.second->Update(_player);
		}
	}
}

void PlayerAttack::Draw() {
	int i = 10;
	for (auto weapon : _weapons) {
		if (weapon.second != nullptr) {
			weapon.second->Draw();
			DrawRotaGraph(43 + i, 43, 0.1, 0.0, weapon.second->Get_Img(), TRUE);
		}
		i += 40;
	}
	for (int i = 10; i < 240; i += 40) {
		DrawBox(23 + i, 23, 63 + i, 63, GetColor(255, 255, 255), FALSE);
	}
}

//武器の追加
void PlayerAttack::Add_Weapon(const char* key, std::shared_ptr<IWeapon> weapon) {
	_weapons[key] = weapon;
}
//武器のレベルアップ
void PlayerAttack::LevelUp(const char* key) {
	auto weapon = _weapons[key];
	weapon->LevelUp();
}
//現在の武器レベル
int PlayerAttack::Current_Level(const char* key) {
	auto weapon = _weapons[key];
	return weapon->Current_Level();
}
//その武器を持っているか
bool PlayerAttack::Search_Weapon(const char* key) {
	auto it = _weapons.find(key);
	if (_weapons.end() == it) {
		return true;
	}
	else {
		return false;
	}
}