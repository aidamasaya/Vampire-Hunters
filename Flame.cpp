#include "stdafx.h"
#include "Flame.h"
#include "SkillData.h"
#include "keyboard.h"

Flame::Flame() {
	_data = std::make_unique<FlameLevel>();
	_img = SkillData::Get_Data(2)._img[0];
	_status._power = SkillData::Get_Data(2)._power;
	_status._speed = SkillData::Get_Data(2)._speed;
	_status._cooldown = SkillData::Get_Data(2)._cooldown * 30;
	_cool = _status._cooldown;
	_status._range = SkillData::Get_Data(2)._range;
	_status._timer = SkillData::Get_Data(2)._timer;
	_level = 1;

	auto flame = std::make_shared<Flame>(_status, _level);
	flame->Start();
	_children.push_back(flame);
}

Flame::Flame(weapon_data data, int level) {
	_data = std::make_unique<FlameLevel>();
	_img = SkillData::Get_Data(2)._img[0];
	_status._power = data._power;
	_status._speed = data._speed;
	_status._cooldown = data._cooldown;
	_status._range = data._range;
	_status._timer = data._timer;

	_level = level;
}

void Flame::Start() {
	_objectType = (int)ObjectType::Weapon;
	Transform.Size.Radius = 20;

	///コリジョン生成
	Setup_Collider<CircleCollider>(Collider::WEAPON);
}

void Flame::Update(std::shared_ptr<IGameObject> player) {
	Children(player);
	Move();

	if (_flag == false) {
		Transform.Position.X = player->Transform.Position.X;
		Transform.Position.Y = player->Transform.Position.Y;
		_flag = true;
	}

	_counter++;
	_sec = _counter / 30;
	//ランダムな角度の決定
	if (_sec < 1) {
		x = GetRand(Define::PI * 2);
		y = GetRand(Define::PI * 2);
	}
	//画面外が出たら非アクティブ化
	if (Transform.Position.X < Define::WIN_W + 100 && Transform.Position.X > -100
		&& Transform.Position.Y < Define::WIN_H + 100 && Transform.Position.Y > -100) {
		Transform.Position.X += cos(x) * _status._speed;
		Transform.Position.Y += sin(y) * _status._speed;
		ColliderManager::CalcStack(_collider);
	}
	else {
		_flag = false;
		_counter = 0;
		_sec = 0;
		_cool = _status._cooldown;
	}
}

void Flame::Children(std::shared_ptr<IGameObject> player) {
	if (_children.size() > 0) {
		for (auto c : _children) {
			c->Update(player);
			c->Draw();
		}
	}
}

void Flame::Draw() {
	auto p = _player.lock();
	double angle = atan2(y, x);
	if (_sec > 1) {
		DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, _status._range, angle, _img, TRUE, Dir.X);
	}
}

bool Flame::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;
}

bool Flame::CoolDown() {
	_cool--;
	if (_cool < 0) {
		_cool = 0;
		return true;
	}
	return false;
}

void Flame::LevelUp() {
	if (_level >= 8) return;
	++_level;
	auto data = _data->Get_Data(_level);
	_status._power += data._power;
	_status._speed += data._speed;
	_status._cooldown -= data._cooldown;
	_status._range += data._range;
	_status._timer += data._timer;

	if (_children.size() > 0) {
		for (auto c : _children) {
			c->_status._power = _status._power;
			c->_status._speed = _status._speed;
			c->_status._cooldown = _status._cooldown;
			c->_cool = c->_status._cooldown;
			c->_status._range = _status._range;
			c->_status._timer = _status._timer;
		}
	}
}

//偽スクロール
void Flame::Move() {
	if (Keyboard::getPressingCount(KEY_INPUT_LEFT) > 0) {
		Transform.Position.X += 2;
	}if (Keyboard::getPressingCount(KEY_INPUT_RIGHT) > 0) {
		Transform.Position.X -= 2;
	}if (Keyboard::getPressingCount(KEY_INPUT_DOWN) > 0) {
		Transform.Position.Y -= 2;
	}if (Keyboard::getPressingCount(KEY_INPUT_UP) > 0) {
		Transform.Position.Y += 2;
	}
}