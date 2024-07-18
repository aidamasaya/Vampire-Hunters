#include "stdafx.h"
#include "MagicBall.h"
#include "keyboard.h"
#include "SkillData.h"

MagicBall::MagicBall() {
	_data = std::make_unique<MagicBallLevel>();
	_img = SkillData::Get_Data(4)._img[0];
	_name = SkillData::Get_Data(4)._name;
	_status._power = SkillData::Get_Data(4)._power;
	_status._speed = SkillData::Get_Data(4)._speed;
	_status._cooldown = SkillData::Get_Data(4)._cooldown * 30;
	_cool = _status._cooldown;
	_status._range = SkillData::Get_Data(4)._range;
	_status._timer = SkillData::Get_Data(4)._timer;

	_level = 1;
	Dir = Vector2(1, 1);
}

MagicBall::MagicBall(weapon_data data, int level) {
	_data = std::make_unique<MagicBallLevel>();
	_img = SkillData::Get_Data(4)._img[0];
	_name = SkillData::Get_Data(4)._name;
	_status._power = data._power;
	_status._speed = data._speed;
	_status._cooldown = data._cooldown;
	_cool = _status._cooldown;
	_status._range = data._range;
	_status._timer = data._timer;

	_level = level;
	Dir = Vector2(1, 1);
}

void MagicBall::Start() {
	_objectType = (int)ObjectType::Weapon;
	Transform.Size.Radius = 30;

	Setup_Collider<CircleCollider>(Collider::WEAPON);
}

void MagicBall::Update(std::shared_ptr<IGameObject> player) {
	Children(player);
	if (CoolDown() == false) return;

	_counter++;
	_sec = _counter / 30;

	Reset(player);
	Bound();

	Transform.Position.X += cos(x) * _status._speed * Dir.X;
	Transform.Position.Y += sin(y) * _status._speed * Dir.Y;
	ColliderManager::CalcStack(_collider);
}

void MagicBall::Children(std::shared_ptr<IGameObject> player) {
	if (_children.size() > 0) {
		for (auto c : _children) {
			c->Update(player);
			c->Draw();
		}
	}
}

//プレイヤーの位置に戻して、ランダムな角度を決定
void MagicBall::Reset(std::shared_ptr<IGameObject> player) {
	if (_flag == true || _sec > 1) return;

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

//跳ね返り処理
void MagicBall::Bound() {
	if (10 < _sec) {
		_flag = false;
		_draw = false;
		_counter = 0;
		_sec = 0;
		_cool = _status._cooldown;
	}

	if (Transform.Position.X + 50 > Define::WIN_W || Transform.Position.X - 50 < 0) {
		Dir.X *= -1;
	}
	else if (Transform.Position.Y + 50 > Define::WIN_H || Transform.Position.Y - 50 < 0) {
		Dir.Y *= -1;
	}
}

void MagicBall::Draw() {
	if (_draw == false) return;
	auto p = _player.lock();
	double angle = atan2(y, x);
	if (_sec > 1) {
		DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, _status._range, angle, _img, TRUE, Dir.X);
	}
}

bool MagicBall::Hit_Callback(std::shared_ptr<Collider> collider) {
	return false;
}

bool MagicBall::CoolDown() {
	_cool--;
	if (_cool < 0) {
		_draw = true;
		_cool = 0;
		return true;
	}
	return false;
}

void MagicBall::LevelUp() {
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
		auto ball = std::make_shared<MagicBall>(_status, _level);
		ball->Start();
		_children.push_back(ball);
	}
}