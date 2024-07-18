#pragma once

#include "stdafx.h"
#include "IPlayerState.h"
#include "IPause.h"
#include "IWeapon.h"
#include <map>

/// <summary>
/// ���ݏ������Ă��镐��𐧌䂷��N���X�A�C���^�[�t�F�C�X���p��
/// </summary>
class IWeapon;
class PlayerAttack : public IPlayerState, public IPause {
	bool _flag;
	//����̖��O�ƕ���N���X�̃Z�b�g�Ŋi�[
	std::map<const char*, std::shared_ptr<IWeapon>> _weapons;

	std::shared_ptr<IGameObject> _player;
public:
	PlayerAttack();
	virtual ~PlayerAttack() {};

	void Start(std::shared_ptr<IGameObject>);
	void Update();
	void Draw();

	int Current_Level(const char* key);
	void Add_Weapon(const char*, std::shared_ptr<IWeapon>);
	void LevelUp(const char*);
	bool Search_Weapon(const char*);

	//�|�[�Y�C���^�[�t�F�C�X����
	void Move_All() { _flag = true; }
	void Stop_All() { _flag = false; }
};