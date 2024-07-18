#pragma once

#include "stdafx.h"
#include "IPlayerState.h"
#include "IPause.h"
#include "IWeapon.h"
#include <map>

/// <summary>
/// 現在所持している武器を制御するクラス、インターフェイスを継承
/// </summary>
class IWeapon;
class PlayerAttack : public IPlayerState, public IPause {
	bool _flag;
	//武器の名前と武器クラスのセットで格納
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

	//ポーズインターフェイス実装
	void Move_All() { _flag = true; }
	void Stop_All() { _flag = false; }
};