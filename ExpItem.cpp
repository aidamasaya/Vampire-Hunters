#include "stdafx.h"
#include "ExpItem.h"
#include "ItemData.h"

//�摜�ƒl�N���X�̏�����
ExpItem::ExpItem() {
	_flag = false;
	_img = ItemData::Get_Data(1)._img;
	item_Exp = new Exp();
	item_Exp->_exp = 1;
}

void ExpItem::SetUp(Transform2D pos) {
	_objectType = (int)ObjectType::Item;
	Transform.Size.Radius = 30;
	Setup_Collider<CircleCollider>(Collider::ITEM);
	Transform = pos;
}

void ExpItem::Update() {
	if (_flag == false) return;
	ColliderManager::CalcStack(_collider);
}

//�o���l�����Z������
void ExpItem::Action() {
	auto e = player_Exp.lock();
	e->Add_Exp(item_Exp);
}

void ExpItem::Draw() {
	if (_flag == false) return;
	DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, 0.2, 0.0, _img, TRUE);
}

/// <summary>
/// �o���l�����Z������
/// </summary>
/// <param name="target">�v���C���[</param>
/// <returns>�v���C���[��������true</returns>
bool ExpItem::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;
	auto go = target->Get_Object().lock();
	if (go->Get_Object_Type<ObjectType>() != ObjectType::Player) return false;

	Action();
	Destroy();
	_flag = false;
	return true;
}