#include "stdafx.h"
#include "Whip.h"
#include "SkillData.h"

//データを貰って初期化
Whip::Whip() {
	_data = std::make_unique<WhipLevel>();
	_img = SkillData::Get_Data(0)._img[0];
	_name = SkillData::Get_Data(0)._name;
	_status._power = SkillData::Get_Data(0)._power;
	_status._speed = SkillData::Get_Data(0)._speed;
	_status._cooldown = SkillData::Get_Data(0)._cooldown * 30;
	_cool = _status._cooldown;
	_status._range = SkillData::Get_Data(0)._range;
	_status._timer = SkillData::Get_Data(0)._timer;

	_level = 1;
}

//子クラスの初期化,親クラスのパラメーターをコピー
Whip::Whip(weapon_data data, int level) {
	_data = std::make_unique<WhipLevel>();
	_img = SkillData::Get_Data(0)._img[0];
	_name = SkillData::Get_Data(0)._name;
	_status._power = data._power;
	_status._speed = data._speed;
	_status._cooldown = data._cooldown;
	_cool = _status._cooldown;
	_status._range = data._range;
	_status._timer = data._timer;

	_level = level;
}


void Whip::Start() {
	_objectType = (int)ObjectType::Weapon;
	Transform.Size.Radius = 30;

	///コリジョン生成
	Setup_Collider<CircleCollider>(Collider::WEAPON);
}

//攻撃の処理
void Whip::Update(std::shared_ptr<IGameObject> player) {
	Children(player); //子クラスを呼び出す
	if (CoolDown() == false) return; //クールダウン

	if (_flag == false) { //位置をセット
		Dir.X = player->Dir.X;
		Transform.Position.X = player->Transform.Position.X + 80 * player->Dir.X;
		Transform.Position.Y = player->Transform.Position.Y + player->Dir.Y;
		_flag = true;
	}

	_counter++;
	_sec = _counter / 30;
	ColliderManager::CalcStack(_collider);
	if (_sec > _status._timer) { //一定時間経ったら攻撃をやめる
		_flag = false;
		_draw = false;
		_counter = 0;
		_cool = _status._cooldown;
	}
}

/// <summary>
///子クラスの制御
/// </summary>
/// <param name="player">プレイヤー</param>
void Whip::Children(std::shared_ptr<IGameObject> player) {
	if (_children.size() > 0) { //子クラスがあれば処理をする
		Vector2 prev;
		prev.X = Dir.X;
		for (auto c : _children) {
			prev.X *= -1;
			prev.Y += 60;
			c->Dir.X = prev.X;
			c->Transform.Position.X = player->Transform.Position.X + 80 * c->Dir.X;
			c->Transform.Position.Y = player->Transform.Position.Y - prev.Y;
			c->Update(player);
			c->Draw();
		}
	}
}

void Whip::Draw() {
	if (_draw == false) return;
	DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, _status._range, 0.0, _img, TRUE, Dir.X);
	//DrawCircle((int)(Transform.Position.X), (int)(Transform.Position.Y), (int)Transform.Size.Radius, GetColor(256, 64, 64), TRUE);
}

bool Whip::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;
	return true;
}

//クールダウン中は非アクティブ
bool Whip::CoolDown() {
	_cool--;
	if (_cool < 0) {
		_draw = true;
		_cool = 0;
		return true;
	}
	return false;
}

//レベルアップ処理
void Whip::LevelUp() {
	if (_level >= 8) return;
	++_level;//レベルアップ
	auto data = _data->Get_Data(_level); //現在のレベルから上昇値のデータをもらう
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
		auto whip = std::make_shared<Whip>(_status, _level);
		whip->Start();
		_children.push_back(whip);
	}
}
