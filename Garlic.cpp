#include "stdafx.h"
#include "Garlic.h"
#include "SkillData.h"

Garlic::Garlic() {
	_data = std::make_unique<GarlicLevel>();
	_img = SkillData::Get_Data(3)._img[0];
	_status._power = SkillData::Get_Data(3)._power;
	_status._speed = SkillData::Get_Data(3)._speed;
	_status._cooldown = SkillData::Get_Data(3)._cooldown * 30;
	_cool = _status._cooldown;
	_status._range = SkillData::Get_Data(3)._range;
	_status._timer = SkillData::Get_Data(3)._timer;

	_level = 1;
}

void Garlic::Start() {
	_objectType = (int)ObjectType::Weapon;
	Transform.Size.Radius = 50;

	///コリジョン生成
	Setup_Collider<CircleCollider>(Collider::WEAPON);
}

//プレイヤーの周りに展開
void Garlic::Update(std::shared_ptr<IGameObject> player) {
	Transform.Position = player->Transform.Position;
	_counter++;
	_sec = _counter / 30;
	ColliderManager::CalcStack(_collider);
	if (_sec > _status._timer) {
		_flag = false;
		_draw = false;
		_counter = 0;
		_cool = _status._cooldown;
	}
	if (CoolDown() == false) return;
}

void Garlic::Draw() {
	if (_draw == true) {
		DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, _status._range, Define::PI * ((double)_status._timer * 0.01), _img, TRUE, Dir.X);
	}
	else {
		DrawCircle(Transform.Position.X, Transform.Position.Y, 20, GetColor(64, 64, 255), TRUE);
	}
	//DrawCircle((int)(Transform.Position.X), (int)(Transform.Position.Y), (int)Transform.Size.Radius, GetColor(64, 64, 64), TRUE);
}

bool Garlic::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;
	return true;
}

bool Garlic::CoolDown() {
	_cool--;
	if (_cool < 0) {
		_draw = true;
		_cool = 0;
		return true;
	}
	return false;
}

void Garlic::LevelUp() {
	if (_level >= 8) return;
	++_level;

	auto data = _data->Get_Data(_level);
	_status._power += data._power;
	_status._speed += data._speed;
	_status._cooldown -= data._cooldown;
	_cool = _status._cooldown;
	_status._range += data._range;
	_status._timer += data._timer;
}