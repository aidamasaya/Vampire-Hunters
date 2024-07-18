#include "stdafx.h"
#include "Cross.h"
#include "SkillData.h"

Cross::Cross() {
	_data = std::make_unique<CrossLevel>();
	_img = SkillData::Get_Data(5)._img[0];
	_name = SkillData::Get_Data(5)._name;
	_status._power = SkillData::Get_Data(5)._power;
	_status._speed = SkillData::Get_Data(5)._speed;
	_speed = _status._speed;
	_status._cooldown = SkillData::Get_Data(5)._cooldown * 30;
	_cool = _status._cooldown;
	_status._range = SkillData::Get_Data(5)._range;
	_status._timer = SkillData::Get_Data(5)._timer;

	_level = 1;

	Dir = Vector2(1, 1);
}

Cross::Cross(weapon_data data, int level) {
	_data = std::make_unique<CrossLevel>();
	_img = SkillData::Get_Data(5)._img[0];
	_name = SkillData::Get_Data(5)._name;
	_status._power = data._power;
	_status._speed = data._speed;
	_speed = _status._speed;
	_status._cooldown = data._cooldown;
	_cool = _status._cooldown;
	_status._range = data._range;
	_status._timer = data._timer;

	_level = level;
	Dir = Vector2(1, 1);
}

void Cross::Start() {
	_objectType = (int)ObjectType::Weapon;
	Transform.Size.Radius = 30;

	//コリジョン生成
	Setup_Collider<CircleCollider>(Collider::WEAPON);
}

void Cross::Update(std::shared_ptr<IGameObject> player) {
	Children(player);
	Reset(player);
	if (CoolDown() == false) return;

	_counter++;
	_sec = _counter / 30;

	//3秒までの間、徐々に減速させる
	if (_sec < 3) {
		_speed -= 0.2;
	}

	//画面外に出たら非アクティブ化
	if (Transform.Position.X < Define::WIN_W + 100 && Transform.Position.X > -100
		&& Transform.Position.Y < Define::WIN_H + 100 && Transform.Position.Y > -100) {
		Transform.Position.X += cos(x) * _speed * Dir.X;
		Transform.Position.Y += sin(y) * _speed * Dir.Y;
		ColliderManager::CalcStack(_collider);
	}
	else {
		_flag = false;
		_draw = false;
		_counter = 0;
		_sec = 0;
		_speed = _status._speed;
		_cool = _status._cooldown;
	}
}

void Cross::Reset(std::shared_ptr<IGameObject> player) {
	if (_flag == true || _draw == true) return;

	if (_flag == false) {
		Transform.Position.X = player->Transform.Position.X;
		Transform.Position.Y = player->Transform.Position.Y;
		_flag == true;
	}
	if (_sec < 1) {
		x = GetRand(360);
		y = GetRand(360);
	}
}

void Cross::Children(std::shared_ptr<IGameObject> player) {
	if (_children.size() > 0) {
		for (auto c : _children) {
			c->Update(player);
			c->Draw();
		}
	}
}

void Cross::Draw() {
	if (_draw == false) return;
	auto p = _player.lock();
	DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, _status._range, Define::PI * ((double)_counter * 0.03), _img, TRUE, Dir.X);
}

bool Cross::Hit_Callback(std::shared_ptr<Collider> collider) {
	return false;
}

bool Cross::CoolDown() {
	_cool--;
	if (_cool < 0) {
		_cool = 0;
		_draw = true;
		return true;
	}
	return false;
}

void Cross::LevelUp() {
	if (_level >= 8) return;
	++_level;
	auto data = _data->Get_Data(_level);
	_status._power += data._power;
	_status._speed += data._speed;
	_status._cooldown -= data._cooldown;
	_cool = _status._cooldown;
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
	if (data._add == true) {
		auto ball = std::make_shared<Cross>(_status, _level);
		ball->Start();
		_children.push_back(ball);
	}
}