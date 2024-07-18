#include "stdafx.h"
#include "Collider.h"

Collider::Collider(COLLIDER_TYPE type, std::weak_ptr<IGameObject> link)
{
	_target = link;

	_type = type;
	_tag = COLLIDER_TAG::INVALID_TAG;
}

Collider::~Collider() {
}

void Collider::Update_Tag(COLLIDER_TAG tag) {
	_tag = tag;
	if (_tag > COLLIDER_TAG::INVALID_TAG) {
		ColliderManager::CalcStack(Get_Ptr());
	}

}

void Collider::Set_Callback(std::function<bool(std::shared_ptr<Collider>)> callback) {
	_hitCallback = callback;
}

//円判定
bool IsHitCircle(const Vector2& a, const Vector2& b, float r) {
	float x = a.X - b.X;
	float y = a.Y - b.Y;


	return x * x + y * y < r * r;
}

//円とAABB
bool IsHitCircleToRect(std::shared_ptr<Collider> circle, std::shared_ptr<Collider> rect) {
	auto tgt = rect->Get_Object().lock();
	auto self = circle->Get_Object().lock();

	float x = self->Transform.Position.X;
	float y = self->Transform.Position.Y;
	float r = self->Transform.Size.Radius;

	//長方形2つと点の判定と、長方形の各点と円の判定
	float x1 = tgt->Transform.Position.X - tgt->Transform.Size.X / 2;
	float x2 = tgt->Transform.Position.X + tgt->Transform.Size.X / 2;
	float y1 = tgt->Transform.Position.Y - tgt->Transform.Size.Y / 2;
	float y2 = tgt->Transform.Position.Y + tgt->Transform.Size.Y / 2;

	if (x1 - r < x && x < x2 + r && y1 < y && y < y2) return true;
	if (x1 < x && x < x2 && y1 - r < y && y < y2 + r) return true;
	if (IsHitCircle(Vector2(x1, y1), self->Transform.Position, r)) return true;
	if (IsHitCircle(Vector2(x2, y1), self->Transform.Position, r)) return true;
	if (IsHitCircle(Vector2(x1, y2), self->Transform.Position, r)) return true;
	if (IsHitCircle(Vector2(x2, y2), self->Transform.Position, r)) return true;

	return false;
}

bool CircleToRectCollider::IsHit(std::shared_ptr<Collider> target)
{
	//当たったコライダー
	switch (target->Get_Type())
	{
		//AABB対AABB
	case COLLIDER_TYPE::RECT:
	{
		auto link = target->Get_Object();
		auto tgt = link.lock();
		auto self = _target.lock();

		float xa1 = (tgt->Transform.Position.X - tgt->Transform.Size.X / 2);
		float xb1 = (self->Transform.Position.X - self->Transform.Size.X / 2);
		float ya1 = (tgt->Transform.Position.Y - tgt->Transform.Size.Y / 2);
		float yb1 = (self->Transform.Position.Y - self->Transform.Size.Y / 2);
		float xa2 = (tgt->Transform.Position.X + tgt->Transform.Size.X / 2);
		float xb2 = (self->Transform.Position.X + self->Transform.Size.X / 2);
		float ya2 = (tgt->Transform.Position.Y + tgt->Transform.Size.Y / 2);
		float yb2 = (self->Transform.Position.Y + self->Transform.Size.Y / 2);

		return xa1 <= xb2 && xa2 >= xb1 && ya1 <= yb2 && ya2 >= yb1;
	}
	break;

	case COLLIDER_TYPE::CIRCLE:
	{
		return IsHitCircleToRect(target, Get_Ptr());
	}
	break;
	}

	return false;
}

bool CircleCollider::IsHit(std::shared_ptr<Collider> target)
{
	//当たったコライダー
	switch (target->Get_Type())
	{
		//円対円
	case COLLIDER_TYPE::CIRCLE:
	{
		auto link = target->Get_Object();
		auto tgt = link.lock();
		auto self = _target.lock();

		//衝突判定
		return IsHitCircle(tgt->Transform.Position, self->Transform.Position
			, tgt->Transform.Size.Radius + self->Transform.Size.Radius);
	}
	break;

	//円対AABB
	case COLLIDER_TYPE::RECT:
	{
		return IsHitCircleToRect(Get_Ptr(), target);
	}
	break;
	}
	return false;
}