#include "stdafx.h"
#include "ColliderManager.h"

//シングルトンインスタンス
static std::unique_ptr<ColliderManager> _instance;
ColliderManager* Get_ColliderManager_Instance()
{
	return _instance.get();
}

ColliderManager::ColliderManager()
{
	_colliders[(int)Collider::COLLIDER_TAG::WEAPON].reserve(100);
}

//動いたオブジェクトの記録
void ColliderManager::CalcStack(std::shared_ptr<Collider> collision)
{
	Get_ColliderManager_Instance()->_calcStack.push_back(collision);
}

//特定のタグに登録されているオブジェクト全部と当たり判定を取る
void ColliderManager::HitToAll(std::shared_ptr<Collider> collision, Collider::COLLIDER_TAG tag)
{
	for (auto itr = _colliders[(int)tag].begin(); itr != _colliders[(int)tag].end(); ++itr)
	{
		if (collision->IsHit(*itr))
		{
			collision->_hitCallback((*itr));
			(*itr)->_hitCallback(collision);
		}
	}
}

//処理実行
void ColliderManager::Run()
{
	auto& removes = Get_ColliderManager_Instance()->_remove_List;
	for (auto itr = removes.begin(); itr != removes.end(); ++itr)
	{
		auto& lists = Get_ColliderManager_Instance()->_colliders[(int)itr->second];

		for (auto itr2 = lists.begin(); itr2 != lists.end(); ++itr2)
		{
			if (*itr2 == itr->first)
			{
				lists.erase(itr2);
				break;
			}
		}
	}

	//動いているものだけ判定する
	auto& calcStacks = Get_ColliderManager_Instance()->_calcStack;
	for (auto itr = calcStacks.begin(); itr != calcStacks.end(); ++itr)
	{
		auto tag = (*itr)->Get_Tag();
		switch (tag)
		{
		case Collider::WEAPON:
			Get_ColliderManager_Instance()->HitToAll((*itr), Collider::COLLIDER_TAG::ENEMY);
			Get_ColliderManager_Instance()->HitToAll((*itr), Collider::COLLIDER_TAG::INVALID_TAG);
			break;
		case Collider::PLAYER:
			Get_ColliderManager_Instance()->HitToAll((*itr), Collider::COLLIDER_TAG::ENEMY);
			Get_ColliderManager_Instance()->HitToAll((*itr), Collider::COLLIDER_TAG::ITEM);
			break;
		case Collider::ENEMY:
			Get_ColliderManager_Instance()->HitToAll((*itr), Collider::COLLIDER_TAG::ENEMY);
			Get_ColliderManager_Instance()->HitToAll((*itr), Collider::COLLIDER_TAG::WEAPON);
			break;
		case Collider::ITEM:
			Get_ColliderManager_Instance()->HitToAll((*itr), Collider::COLLIDER_TAG::PLAYER);
			break;
		case Collider::INVALID_TAG:
			Get_ColliderManager_Instance()->HitToAll((*itr), Collider::COLLIDER_TAG::ITEM);
			Get_ColliderManager_Instance()->HitToAll((*itr), Collider::COLLIDER_TAG::WEAPON);
			break;
		}
	}

	calcStacks.clear();
}

void ColliderManager::Register(std::shared_ptr<Collider> collision, Collider::COLLIDER_TAG tag)
{
	Get_ColliderManager_Instance()->_colliders[(int)tag].push_back(collision);
}

void ColliderManager::Remove(std::shared_ptr<Collider> collision, Collider::COLLIDER_TAG tag)
{
	Get_ColliderManager_Instance()->_remove_List.push_back(std::pair<std::shared_ptr<Collider>, Collider::COLLIDER_TAG>(collision, tag));
}

void ColliderManager::Create()
{
	if (_instance == nullptr)
	{
		_instance = std::unique_ptr<ColliderManager>(new ColliderManager());
	}
}

void ColliderManager::Release()
{
	_instance.release();
}