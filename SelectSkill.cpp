#include "stdafx.h"
#include "SelectSkill.h"
#include "keyboard.h"

bool SelectSkill::Main() {
	Draw();
	return Select();
}


void SelectSkill::Setup() {
	_font = std::make_unique<FontData>("C:/Users/mynhj/Downloads/misaki_png_2021-05-05a/misaki_gothic_2nd.png", 23, 3);

	weapon_Data.push_back(std::make_unique<WeaponData>(0));
	weapon_Data.push_back(std::make_unique<WeaponData>(1));
	weapon_Data.push_back(std::make_unique<WeaponData>(2));
	weapon_Data.push_back(std::make_unique<WeaponData>(3));
	weapon_Data.push_back(std::make_unique<WeaponData>(4));
	weapon_Data.push_back(std::make_unique<WeaponData>(5));

	_creator = std::make_unique<WeaponCreator>();
	auto weapon = _creator->Get_Weapon(weapon_Data[0]->Get_Name());
	weapon->Start();
	_attack->Add_Weapon("鞭", weapon);
}

void SelectSkill::Start() {
	if (_flag == false || Select_Num != 0) {
		Select_Num = 0;
		Random();
		_flag = true;
	}
}

void SelectSkill::Random() {
	for (int i = 0; i < 4;) {
		int r = GetRand(weapon_Data.size() - 1);
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			if (r == random_weapon[j]) {
				flag = false;
			}
		}if (flag) {
			random_weapon[i] = r;
			i++;
		}
	}
}

bool SelectSkill::Select() {
	if (Keyboard::getPressingCount(KEY_INPUT_DOWN) == 1) { // 下キーが押された瞬間だけ処理
		Select_Num = (Select_Num + 1) % 4; // 現在の選択項目を一つ下にずらす(ループする)
	}
	if (Keyboard::getPressingCount(KEY_INPUT_UP) == 1) { // 上キーが押された瞬間だけ処理
		Select_Num = (Select_Num + 3) % 4; // 現在の選択項目を一つ下にずらす(ループする)
	}

	if (Keyboard::getPressingCount(KEY_INPUT_RETURN) == 1) {
		Add_Skill(Select_Num);
		_flag = false;
		return false;
	}
	return true;
}

void SelectSkill::Add_Skill(int num) {
	auto name = weapon_Data[random_weapon[num]]->Get_Name();
	if (_attack->Search_Weapon(name) == true) {
		auto weapon = _creator->Get_Weapon(name);
		weapon->Start();
		_attack->Add_Weapon(name, weapon);
	}
	else {
		_attack->LevelUp(name);
		weapon_Data[random_weapon[num]]->Add_Level();
		if (weapon_Data[random_weapon[num]]->Get_Level() >= 8) {
			for (auto itr = weapon_Data.begin(); itr != weapon_Data.end(); ++itr) {
				if (weapon_Data[random_weapon[num]] == *itr) {
					weapon_Data.erase(itr);
					return;
				}
			}
		}
	}
}

void SelectSkill::Draw() {
	for (int i = 1; i < 5; i++) {
		DrawBox(Define::WIN_W / 4 + 100, 130 * i,
			Define::WIN_W / 4 + 600, 130 * i + 70, GetColor(200, 200, 200), TRUE);

		DrawRotaGraph(Define::WIN_W / 4 + 150, 130 * i + 35, 0.2, 0.0,
			weapon_Data[random_weapon[i - 1]]->Get_Img(), TRUE);

		if (_attack->Search_Weapon(weapon_Data[random_weapon[i - 1]]->Get_Name()) != true) {
			DrawFormatString(Define::WIN_W / 4 + 400, 130 * i + 5, GetColor(255, 255, 255),
				"レベル : %2d", weapon_Data[random_weapon[i - 1]]->Get_Level() + 1, TRUE);
		}
		else DrawFormatString(Define::WIN_W / 4 + 400, 130 * i + 5, GetColor(255, 255, 255), "New", TRUE);

		DrawFormatString(Define::WIN_W / 4 + 200, 130 * i + 5, GetColor(255, 255, 255), weapon_Data[random_weapon[i - 1]]->Get_Name(), TRUE);

		DrawFormatStringToHandle(Define::WIN_W / 4 + 200, 130 * i + 20, GetColor(255, 255, 255),
			_font->Get_Font(), weapon_Data[random_weapon[i - 1]]->Get_Des(), TRUE);

	}
	//	DrawRotaGraph(Define::CENTER_X - 430, (Define::CENTER_Y - 200) * Select_Num, 0.1, 0.0,
	//		_pointImg, TRUE);
	DrawCircle(Define::WIN_W / 4 + 70, 130 * (Select_Num + 1) + 30, 10, GetColor(255, 255, 255), TRUE);
	DrawFormatStringToHandle(Define::WIN_W / 4 + 100, 20, _font->Get_Font(), GetColor(255, 255, 0), "LevelUP!!", true);
	//DrawFormatString(Define::IN_X + 250, Define::IN_Y + 550, GetColor(255, 255, 0), "スキルを選んでください", true);
}