#pragma once

#include "Collider.h"
#include <array>
#include <thread>
#include "GameMath.h"
#include "Singleton.h"

/// <summary>
/// 全コライダーを管理するクラス
/// シングルトンを使って、一つのインスタンスで全コライダーを管理できるようにする
/// </summary>
class ColliderManager : public Singleton<ColliderManager>
{
	//タグ分けしてそれぞれのタグのついたオブジェクトを格納する
	std::array<std::vector<std::shared_ptr<Collider>>, Collider::MAX_COLLIDER_TAG> _colliders;
	std::vector<std::shared_ptr<Collider>> _calcStack;
	std::vector<std::pair<std::shared_ptr<Collider>, Collider::COLLIDER_TAG>> _remove_List;

	ColliderManager();

	void HitToAll(std::shared_ptr<Collider> collision, Collider::COLLIDER_TAG tag);

public:
	static void Run();
	static void CalcStack(std::shared_ptr<Collider> collision);
	static void Register(std::shared_ptr<Collider> collision, Collider::COLLIDER_TAG tag);
	static void Remove(std::shared_ptr<Collider> collsiion, Collider::COLLIDER_TAG tag);

	static void Create();
	static void Release();
};