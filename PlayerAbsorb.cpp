#include "stdafx.h"
#include "PlayerAbsorb.h"

//プレイヤーのポインタを受け取る
void PlayerAbsorb::Start(std::shared_ptr<IGameObject> player) {
	_player = player;
	_objectType = (int)ObjectType::Invalid;
	Transform.Size.Radius = 50;
	Setup_Collider<CircleCollider>(Collider::INVALID_TAG);
}

/// <summary>
/// アイテムと接触した吸収する
/// </summary>
/// <param name="target">アイテム</param>
/// <returns>アイテムと接触したらtrue</returns>
bool PlayerAbsorb::Hit_Callback(std::shared_ptr<Collider> target) {
	auto go = target->Get_Object().lock();
	if (go->Get_Object_Type<ObjectType>() != ObjectType::Item) return false;

	Calc(go);

	return true;
}

void PlayerAbsorb::Update() {
	auto p = _player;
	Transform.Position = p->Transform.Position;
	ColliderManager::CalcStack(_collider);
}

void PlayerAbsorb::Draw() {
	auto p = _player;
	//DrawCircle(Transform.Position.X, Transform.Position.Y, Transform.Size.Radius, GetColor(255, 64, 64), TRUE);
}

//アイテムを吸収する計算処理
void PlayerAbsorb::Calc(std::shared_ptr<IGameObject> b) {
	float min_Distance = Transform.Size.Radius + b->Transform.Size.Radius;

	float dx = Transform.Position.X - b->Transform.Position.X;
	float dy = Transform.Position.Y - b->Transform.Position.Y;
	dx *= 0.14f;
	dy *= 0.14f;
	b->Transform.Position.X += dx;
	b->Transform.Position.Y += dy;
}