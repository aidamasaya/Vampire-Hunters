#pragma once

#include "stdafx.h"
#include "IPlayerState.h"
#include "PlayerMove.h"
#include "PlayerAbsorb.h"
#include "PlayerAttack.h"
#include "PlayerHealth.h"
#include "PlayerMoney.h"
#include "PlayerLevel.h"

/// <summary>
/// �v���C���[�֌W�̏�����f�[�^���܂Ƃ߂Đ��䂷��N���X
/// </summary>
class PlayerHealth;
class PlayerController : public IGameObject, public IPause {
	//�v���C���[�̏ڍׂȓ����̓C���^�[�t�F�C�X�Ŏ�������
	std::vector<std::shared_ptr<IPlayerState>> _subclasses;

	float _def;

	//�v���C���[�f�[�^�N���X
	std::shared_ptr<PlayerHealth> _health;
	std::shared_ptr<PlayerMoney> _money;
	std::shared_ptr<PlayerLevel> _level;

	bool _flag;
public:
	PlayerController();
	virtual ~PlayerController() {};

	bool Hit_Callback(std::shared_ptr<Collider> target);

	void Attach_Subclass(std::shared_ptr<IPlayerState>);

	void Start();
	void Update();
	void Draw();

	//�|�[�Y�C���^�[�t�F�C�X����
	void Move_All() { _flag = true; }
	void Stop_All() { _flag = false; }

	//�f�[�^��n��
	std::shared_ptr<PlayerMoney> Get_Money() { return _money; }
	std::shared_ptr<PlayerHealth> Get_Health() { return _health; }

	//��������
	bool isDeath() {
		if (_health->Current_HP() <= 0) {
			return false;
		}
		return true;
	}
	//���݂̃��x����n��
	std::shared_ptr<PlayerLevel> Get_Level() {
		return _level;
	}
};