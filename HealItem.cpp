#include "stdafx.h"
#include "HealItem.h"
#include "PlayerController.h"
#include "ItemData.h"

//画像と値クラスの初期化
HealItem::HealItem() {
	_flag = false;
	_img = ItemData::Get_Data(2)._img;
	item_Health = new Health();
	item_Health->_health = 30;
}

void HealItem::SetUp(Transform2D pos) {
	_objectType = (int)ObjectType::Item;
	Transform.Size.Radius = 10;
	Transform = pos;

	Setup_Collider<CircleCollider>(Collider::ITEM);
}

void HealItem::Update() {
	if (_flag == false) return;
	ColliderManager::CalcStack(_collider);
}

//プレイヤーのHPを回復
void HealItem::Action() {
	auto e = player_Health.lock();
	e->Heal_HP(item_Health);
}

void HealItem::Draw() {
	if (_flag == false) return;
	DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, 0.1, 0.0, _img, TRUE);
}

/// <summary>
/// プレイヤーのHPを回復
/// </summary>
/// <param name="target">プレイヤー</param>
/// <returns>プレイヤーだったらtrue</returns>
bool HealItem::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;
	auto go = target->Get_Object().lock();
	if (go->Get_Object_Type<ObjectType>() != ObjectType::Player) return false;

	PlayerController* player = dynamic_cast<PlayerController*>(go.get());
	player_Health = player->Get_Health();
	Action();
	Destroy();
	_flag = false;
	return true;
}