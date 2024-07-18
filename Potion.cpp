#include "stdafx.h"
#include "Potion.h"
#include "SkillData.h"

//データを貰って初期化
Potion::Potion() {
	_data = std::make_unique<PotionLevel>();
	_img[0] = SkillData::Get_Data(1)._img[0];
	_img[1] = SkillData::Get_Data(1)._img[1];
	_status._power = SkillData::Get_Data(1)._power;
	_status._speed = SkillData::Get_Data(1)._speed;
	_status._cooldown = SkillData::Get_Data(1)._cooldown * 30;
	_cool = _status._cooldown;
	_status._range = SkillData::Get_Data(1)._range;
	_status._timer = SkillData::Get_Data(1)._timer;

	_level = 1;
}

//子クラスの初期化,親クラスのパラメーターをコピー
Potion::Potion(weapon_data data, int level) {
	_data = std::make_unique<PotionLevel>();
	_img[0] = SkillData::Get_Data(1)._img[0];
	_img[1] = SkillData::Get_Data(1)._img[1];
	_status._power = data._power;
	_status._speed = data._speed;
	_status._cooldown = data._cooldown;
	_cool = _status._cooldown;
	_status._range = data._range;
	_status._timer = data._timer;

	_level = 1;
}

void Potion::Start() {
	_objectType = (int)ObjectType::Weapon;
	Transform.Size.Radius = 20;

	///コリジョン生成
	Setup_Collider<CircleCollider>(Collider::WEAPON);
}

//攻撃の処理
void Potion::Update(std::shared_ptr<IGameObject> player) {
	Children(player);//子クラスを呼び出す
	Move();

	_counter++;
	_sec = _counter / 30;

	if (_sec < 1) {
		Dir.X = GetRand(10000) / 10000 % 2 == 0 ? 1 : -1;
		Transform.Position.X = GetRand(Define::WIN_W / 2) * Dir.X;
		Transform.Position.Y = 0;
	}
	if (1 <= _sec && _sec < 4) {
		Transform.Position.X += _status._speed;
		Transform.Position.Y += _status._speed;
	}
	if (5 <= _sec && _sec < 8) {
		ColliderManager::CalcStack(_collider);
	}
	if (_sec > _status._timer) {
		_flag = false;
		_counter = 0;
		_sec = 0;
		_cool = _status._cooldown;
	}
}

/// <summary>
///子クラスの制御
/// </summary>
/// <param name="player">プレイヤー</param>
void Potion::Children(std::shared_ptr<IGameObject> player) {
	if (_children.size() > 0) { //子クラスがあれば処理をする
		for (auto c : _children) {
			c->Update(player);
			c->Draw();
		}
	}
}

void Potion::Draw() {
	auto p = _player.lock();
	if (1 <= _sec && _sec < 4) {
		DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, 0.2, Define::PI * ((double)_counter * 0.03), _img[0], TRUE, Dir.X);
	}
	if (5 <= _sec && _sec < 8) {
		DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, _status._range, 0.0, _img[1], TRUE, Dir.X);
	}
	//DrawCircle((int)(Transform.Position.X), (int)(Transform.Position.Y), (int)Transform.Size.Radius, GetColor(64, 64, 64), TRUE);
}

bool Potion::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;
	return true;
}

//クールダウン中は非アクティブ
bool Potion::CoolDown() {
	_cool--;
	if (_cool < 0) {
		_cool = 0;
		_flag = true;
		return true;
	}
	return false;
}


//レベルアップ処理
void Potion::LevelUp() {
	if (_level >= 8) return;
	++_level;//レベルアップ

	auto data = _data->Get_Data(_level);//現在のレベルから上昇値のデータをもらう
	_status._power += data._power;
	_status._speed += data._speed;
	_status._cooldown -= data._cooldown;
	_cool = _status._cooldown;
	_status._range += data._range;
	_status._timer += data._timer;
	//子クラスも上昇
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
	//addがtrueなら子クラスを一つ追加
	if (data._add == true) {
		auto potion = std::make_shared<Potion>(_status, _level);
		potion->Start();
		_children.push_back(potion);
	}
}

//詐欺スクロール
void Potion::Move() {
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