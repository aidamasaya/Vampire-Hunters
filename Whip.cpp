#include "stdafx.h"
#include "Whip.h"
#include "SkillData.h"

//�f�[�^�����ď�����
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

//�q�N���X�̏�����,�e�N���X�̃p�����[�^�[���R�s�[
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

	///�R���W��������
	Setup_Collider<CircleCollider>(Collider::WEAPON);
}

//�U���̏���
void Whip::Update(std::shared_ptr<IGameObject> player) {
	Children(player); //�q�N���X���Ăяo��
	if (CoolDown() == false) return; //�N�[���_�E��

	if (_flag == false) { //�ʒu���Z�b�g
		Dir.X = player->Dir.X;
		Transform.Position.X = player->Transform.Position.X + 80 * player->Dir.X;
		Transform.Position.Y = player->Transform.Position.Y + player->Dir.Y;
		_flag = true;
	}

	_counter++;
	_sec = _counter / 30;
	ColliderManager::CalcStack(_collider);
	if (_sec > _status._timer) { //��莞�Ԍo������U������߂�
		_flag = false;
		_draw = false;
		_counter = 0;
		_cool = _status._cooldown;
	}
}

/// <summary>
///�q�N���X�̐���
/// </summary>
/// <param name="player">�v���C���[</param>
void Whip::Children(std::shared_ptr<IGameObject> player) {
	if (_children.size() > 0) { //�q�N���X������Ώ���������
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

//�N�[���_�E�����͔�A�N�e�B�u
bool Whip::CoolDown() {
	_cool--;
	if (_cool < 0) {
		_draw = true;
		_cool = 0;
		return true;
	}
	return false;
}

//���x���A�b�v����
void Whip::LevelUp() {
	if (_level >= 8) return;
	++_level;//���x���A�b�v
	auto data = _data->Get_Data(_level); //���݂̃��x������㏸�l�̃f�[�^�����炤
	_status._power += data._power;
	_status._speed += data._speed;
	_status._cooldown -= data._cooldown;
	_cool = _status._cooldown;
	_status._range += data._range;
	_status._timer += data._timer;
	//�q�N���X���㏸
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
	//add��true�Ȃ�q�N���X����ǉ�
	if (data._add == true) {
		auto whip = std::make_shared<Whip>(_status, _level);
		whip->Start();
		_children.push_back(whip);
	}
}
