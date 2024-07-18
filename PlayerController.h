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
/// プレイヤー関係の処理やデータをまとめて制御するクラス
/// </summary>
class PlayerHealth;
class PlayerController : public IGameObject, public IPause {
	//プレイヤーの詳細な動きはインターフェイスで実装する
	std::vector<std::shared_ptr<IPlayerState>> _subclasses;

	float _def;

	//プレイヤーデータクラス
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

	//ポーズインターフェイス実装
	void Move_All() { _flag = true; }
	void Stop_All() { _flag = false; }

	//データを渡す
	std::shared_ptr<PlayerMoney> Get_Money() { return _money; }
	std::shared_ptr<PlayerHealth> Get_Health() { return _health; }

	//生死判定
	bool isDeath() {
		if (_health->Current_HP() <= 0) {
			return false;
		}
		return true;
	}
	//現在のレベルを渡す
	std::shared_ptr<PlayerLevel> Get_Level() {
		return _level;
	}
};