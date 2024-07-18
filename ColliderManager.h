#pragma once

#include "Collider.h"
#include <array>
#include <thread>
#include "GameMath.h"
#include "Singleton.h"

/// <summary>
/// �S�R���C�_�[���Ǘ�����N���X
/// �V���O���g�����g���āA��̃C���X�^���X�őS�R���C�_�[���Ǘ��ł���悤�ɂ���
/// </summary>
class ColliderManager : public Singleton<ColliderManager>
{
	//�^�O�������Ă��ꂼ��̃^�O�̂����I�u�W�F�N�g���i�[����
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