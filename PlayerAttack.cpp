#include "stdafx.h"
#include "PlayerAttack.h"

PlayerAttack::PlayerAttack() {
	_flag = true;
}
//�v���C���[�̃|�C���^���󂯎��
void PlayerAttack::Start(std::shared_ptr<IGameObject> player) {
	_player = player;
}

//�����Ă��镐��̃��\�b�h���܂Ƃ߂ČĂяo��
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

//����̒ǉ�
void PlayerAttack::Add_Weapon(const char* key, std::shared_ptr<IWeapon> weapon) {
	_weapons[key] = weapon;
}
//����̃��x���A�b�v
void PlayerAttack::LevelUp(const char* key) {
	auto weapon = _weapons[key];
	weapon->LevelUp();
}
//���݂̕��탌�x��
int PlayerAttack::Current_Level(const char* key) {
	auto weapon = _weapons[key];
	return weapon->Current_Level();
}
//���̕���������Ă��邩
bool PlayerAttack::Search_Weapon(const char* key) {
	auto it = _weapons.find(key);
	if (_weapons.end() == it) {
		return true;
	}
	else {
		return false;
	}
}