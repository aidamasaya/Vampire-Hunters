#include "stdafx.h"
#include "CoinItem.h"
#include "PlayerController.h"
#include "ItemData.h"

//�摜�ƒl�N���X�̏�����
CoinItem::CoinItem() {
	_flag = false;
	_img = ItemData::Get_Data(0)._img;
	item_coin = new Coin();
	item_coin->_coin = 1;
}

void CoinItem::SetUp(Transform2D pos) {
	_objectType = (int)ObjectType::Item;
	Transform.Size.Radius = 10;
	Transform = pos;

	Setup_Collider<CircleCollider>(Collider::ITEM);
}

void CoinItem::Update() {
	if (_flag == false) return;
	ColliderManager::CalcStack(_collider);
}

//�v���C���[�̏����������Z������
void CoinItem::Action() {
	auto c = player_Money.lock();
	c->Add_Money(item_coin);
	//player->Add_Coin(_coin);
}

void CoinItem::Draw() {
	if (_flag == false) return;
	DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, 0.2, 0.0, _img, TRUE);
}

/// <summary>
/// �v���C���[�̏����������Z������
/// </summary>
/// <param name="target">�v���C���[</param>
/// <returns>�v���C���[��������true</returns>
bool CoinItem::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;
	auto go = target->Get_Object().lock();
	if (go->Get_Object_Type<ObjectType>() != ObjectType::Player) return false;

	PlayerController* player = dynamic_cast<PlayerController*>(go.get());
	player_Money = player->Get_Money();
	Action();
	_flag = false;
	Destroy();
	return true;
}