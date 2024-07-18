#pragma once

class IGameObject;
class ColliderManager;

/// <summary>
/// 2D�R���C�_�[���
/// Unity�ɂ�����R���C�_�[�R���|�[�l���g�Ƃقړ����ł��B���������ۂɃC�x���g�����s����܂��B
/// </summary>
class Collider : public std::enable_shared_from_this<Collider> {
public:

	enum COLLIDER_TYPE {
		INVALID_TYPE,
		CIRCLE,
		RECT
	};

	enum COLLIDER_TAG {
		INVALID_TAG,
		PLAYER,
		ENEMY,
		WEAPON,
		ITEM,
		MAX_COLLIDER_TAG
	};

private:
	friend ColliderManager;

	COLLIDER_TYPE _type;
	COLLIDER_TAG _tag;

protected:
	std::weak_ptr<IGameObject> _target;
	std::function<bool(std::shared_ptr<Collider>)> _hitCallback;
	std::shared_ptr<Collider> Get_Ptr() { return shared_from_this(); }

	Collider() : _type(COLLIDER_TYPE::CIRCLE), _tag(COLLIDER_TAG::INVALID_TAG) {}
public:
	Collider(COLLIDER_TYPE type, std::weak_ptr<IGameObject> link);
	virtual ~Collider();

	COLLIDER_TYPE Get_Type() { return _type; }
	COLLIDER_TAG Get_Tag() { return _tag; }
	std::weak_ptr<IGameObject> Get_Object() { return _target; }

	void Update_Tag(COLLIDER_TAG tag);
	void Set_Callback(std::function<bool(std::shared_ptr<Collider>)> callback);
	virtual bool IsHit(std::shared_ptr<Collider> target) = 0;
};

/// <summary>
/// �T�[�N���R���C�_�[
/// Unity�ɂ�����CircleCollider2D�Ƃقړ����ł�
/// </summary>
class CircleCollider : public Collider {
	CircleCollider() {}
	CircleCollider(CircleCollider&&) = delete;
public:
	CircleCollider(std::weak_ptr<IGameObject> link) :
		Collider(COLLIDER_TYPE::CIRCLE, link) {}
	bool IsHit(std::shared_ptr<Collider> target);
};

/// <summary>
/// AABB�R���C�_�[
/// Unity�ɂ�����BoxCollider2D�Ƃقړ����ł�
/// </summary>
class CircleToRectCollider : public Collider {
	CircleToRectCollider() {}
	CircleToRectCollider(CircleToRectCollider&&) = delete;
public:
	CircleToRectCollider(std::weak_ptr<IGameObject> link) :
		Collider(COLLIDER_TYPE::RECT, link) {}
	bool IsHit(std::shared_ptr<Collider> target);
};
