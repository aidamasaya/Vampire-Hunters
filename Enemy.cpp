#include "stdafx.h"
#include "Enemy.h"
#include "EnemyData.h"
#include "ItemManager.h"
#include "Pause.h"

Enemy::Enemy() {
	_img = 0;
	_hp = 0;
	_power = 0;
	_speed = 0;
	_flag = false;
}

/// <summary>
/// �G�̃f�[�^���󂯎�菉����
/// </summary>
/// <param name="id">�G�f�[�^��ID</param>
void Enemy::Start(int id) {
	_img = EnemyData::Get_Data(id)._img;
	_hp = EnemyData::Get_Data(id)._hp;
	_power = EnemyData::Get_Data(id)._atk;
	_speed = EnemyData::Get_Data(id)._speed;

	_calc = std::make_shared<EnemyCalc>(GetPtr());
	_objectType = (int)ObjectType::Enemy;
	Transform.Size.Radius = 10;
	Setup_Collider<CircleCollider>(Collider::ENEMY);
}

void Enemy::Update() {
	if (_flag == false) return;
	//�v���C���[��ǂ�������
	_calc->Move(_speed, _player);
}

/// <summary>
/// �Փ˔���
/// </summary>
/// <param name="target">���������Ώ�</param>
/// <returns>�Ώۂ��G�Ȃ狗�����Ƃ�A�v���C���[�̕���Ȃ�_���[�W������true,
/// �ǂ���ł��Ȃ���Ή���������false��Ԃ�
/// </returns>
bool Enemy::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;

	auto go = target->Get_Object().lock();
	if (go->Get_Object_Type<ObjectType>() != ObjectType::Weapon) return false;
	if (go->Get_Object_Type<ObjectType>() == ObjectType::Enemy) {
		_calc->Distance(go);
		return true;
	}

	IWeapon* weapon = dynamic_cast<IWeapon*>(go.get());
	_hp -= weapon->Get_Power();

	if (_hp <= 0) { //HP��0�ɂȂ�����exp���o����A�N�e�B�u��
		Drop();
		Release();
	}
	_calc->KnockBack(go);

	return true;
}

void Enemy::Draw() {
	if (_hp <= 0) return;
	DrawRotaGraph(Transform.Position.X, Transform.Position.Y, 0.2, 0.0, _img, TRUE);
}

void Enemy::Drop() {
	auto manager = _manager.lock();
	if (manager != nullptr) {
		manager->SetUp_Exp(Transform);
	}
}

void Enemy::Release() {
	_flag = false;
	Destroy();
}