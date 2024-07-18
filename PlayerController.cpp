#include "stdafx.h"
#include "PlayerController.h"
#include "BaseItem.h"
#include "Enemy.h"
#include "keyboard.h"

PlayerController::PlayerController() {
	_flag = true;
	_def = 7;
}

//�T�u�N���X�Ɏ��g�̃|�C���^��n���ď�����
void PlayerController::Attach_Subclass(std::shared_ptr<IPlayerState> subclass) {
	subclass->Start(GetPtr());
	_subclasses.push_back(subclass);
}

//�������g�̏�����
void PlayerController::Start() {
	_objectType = (int)ObjectType::Player;
	Transform.Size = Vector2(1, 1);
	Setup_Collider<CircleToRectCollider>(Collider::PLAYER);

	_health = std::make_unique<PlayerHealth>(100);
	_money = std::make_unique<PlayerMoney>();
	_level = std::make_unique<PlayerLevel>();
}

void PlayerController::Update() {
	if (_flag == false) return;

	for (auto s : _subclasses) {
		s->Update();
	}
	ColliderManager::CalcStack(_collider);
}

void PlayerController::Draw() {
	for (auto s : _subclasses) {
		s->Draw();
	}

	_health->Draw(Transform.Position);
	_money->Draw();
}

/// <summary>
/// �G�ɓ���������_���[�W�����炷
/// </summary>
/// <param name="target">�G</param>
/// <returns>����������true</returns>
bool PlayerController::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;
	auto go = target->Get_Object().lock();
	if (go->Get_Object_Type<ObjectType>() != ObjectType::Enemy) return false;

	Enemy* enemy = dynamic_cast<Enemy*>(go.get());
	auto damage = enemy->Get_Power() - _def;
	if (damage < 0) return false;
	_health->Damage_Hp(damage);
	return true;
}