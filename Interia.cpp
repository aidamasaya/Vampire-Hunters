#include "stdafx.h"
#include "Interia.h"
#include "Coin.h"
#include "keyboard.h"

Interia::Interia(std::shared_ptr<ItemManager> manager) {
	_img = LoadGraph("C:/Users/mynhj/source/repos/testc++/event_candle01_02.png");
	_flag = true;
	_active = true;
	_manager = manager;
}
//ランダムに位置をセット
void Interia::Setup() {
	std::random_device seed_gen;
	std::mt19937 mt(seed_gen());

	_objectType = (int)ObjectType::Invalid;
	Transform.Size.Radius = 10;
	Setup_Collider<CircleCollider>(Collider::INVALID_TAG);
	Transform.Position = Vector2((float)(280 + mt() % Define::WIN_W), (float)(350 - mt() % Define::WIN_H));
}

void Interia::Draw() {
	if (_active == false) return;
	auto pos = Transform.Position;
	DrawRotaGraphF(Transform.Position.X, Transform.Position.Y, 0.1, 0.0, _img, TRUE);
}
/// <summary>
/// プレイヤーの武器と接触したらアイテムを出して非アクティブ化
/// </summary>
/// <param name="target"></param>
/// <returns></returns>
bool Interia::Hit_Callback(std::shared_ptr<Collider> target) {
	if (_flag == false) return false;
	auto go = target->Get_Object().lock();
	if (go->Get_Object_Type<ObjectType>() != ObjectType::Weapon) return false;

	auto num = GetRand(3) % 2 == 0 ? 0 : 1;
	if (num == 0) _manager->SetUp_Coin(Transform);
	else _manager->SetUp_Heal(Transform);

	_active = false;
	_flag = false;
	Destroy();
	return true;
}

void Interia::Scroll() {
	if (_flag == false || _active == false) return;

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