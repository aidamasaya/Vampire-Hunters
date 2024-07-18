#pragma once

#include "Whip.h"
#include "Potion.h"
#include "Garlic.h"
#include "Flame.h"
#include "MagicBall.h"
#include "Cross.h"
#include "SkillData.h"

/// <summary>
/// ïêäÌê∂ê¨ÉNÉâÉX
/// </summary>
class Whip;
class Potion;
class GarlicForce;
class Flame;
class MagicBall;
class Cross;
class WeaponCreator {
public:
	WeaponCreator() {};
	virtual ~WeaponCreator() {};

	std::shared_ptr<IWeapon> Get_Weapon(const char* name) {
		if (name == SkillData::Get_Data(0)._name) {
			return std::make_shared<Whip>();
		}
		else if (name == SkillData::Get_Data(1)._name) {
			return std::make_shared<Potion>();
		}
		else if (name == SkillData::Get_Data(2)._name) {
			return std::make_shared<Flame>();
		}
		else if (name == SkillData::Get_Data(3)._name) {
			return std::make_shared<Garlic>();
		}
		else if (name == SkillData::Get_Data(4)._name) {
			return std::make_shared<MagicBall>();
		}
		else if (name == SkillData::Get_Data(5)._name) {
			return std::make_shared<Cross>();
		}
	}
private:
};