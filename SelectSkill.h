#pragma once

#include "IWeapon.h"
#include "FontData.h"
#include "PlayerAttack.h"
#include "WeaponData.h"
#include "WeaponCreator.h"
#include <map>

/// <summary>
/// 武器選択システム
/// </summary>
class FontData;
class PlayerAttack;
class SelectSkill {
	std::shared_ptr<PlayerAttack> _attack;
	std::map<int, const char*> _weapons;
	std::unique_ptr<FontData> _font;
	std::vector<std::unique_ptr<WeaponData>> weapon_Data;
	int random_weapon[4] = { -1,-1,-1,-1 };
	std::unique_ptr<WeaponCreator> _creator;

	int _pointImg = 0;
	bool _flag = false;
	int Select_Num = 0;
	void Draw();
	void Add_Skill(int);
	bool Select();
	void Random();
public:
	SelectSkill(std::shared_ptr<PlayerAttack> attack) { _attack = attack; }
	virtual ~SelectSkill() {};

	void Setup();
	void Start();
	bool Main();

	void Get_flag(bool f) { _flag = f; }
};