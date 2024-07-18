#pragma once

/// <summary>
/// ゲームオブジェクトクラス。UnityのGameObjectほど抽象化されていない
/// </summary>
class Collider;
class IGameObject : public std::enable_shared_from_this<IGameObject> {
protected:
	int _objectType;
	std::string _name;
	std::shared_ptr<Collider> _collider;

	std::shared_ptr<IGameObject> GetPtr() { return shared_from_this(); }

	virtual bool Hit_Callback(std::shared_ptr<Collider> target)
	{
		return true;
	}

	void Destroy()
	{
		ColliderManager::Remove(_collider, _collider->Get_Tag());
	}
public:

	IGameObject() : _objectType(0) {}

	Transform2D Transform;
	Vector2 Dir;

	template<class T>
	T Get_Object_Type() { return (T)_objectType; }

	template<class T>
	void Setup_Collider(Collider::COLLIDER_TAG tag)
	{
		_collider = std::make_shared<T>(std::weak_ptr<IGameObject>(GetPtr()));
		_collider->Update_Tag(tag);
		_collider->Set_Callback(std::bind(&IGameObject::Hit_Callback, &(*this), std::placeholders::_1));
		ColliderManager::Register(_collider, tag);
	}
};