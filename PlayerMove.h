#pragma once

#include "stdafx.h"
#include "IPlayerState.h"

/// <summary>
/// プレイヤーの向きを制御するクラス
/// </summary>
class PlayerMove : public IPlayerState {
	//向いてる方向
	Vector2 _dir;
	std::shared_ptr<IGameObject> _player;
public:
	PlayerMove();
	virtual ~PlayerMove() {};

	void Start(std::shared_ptr<IGameObject>);
	void Update();
	void Draw();

	Vector2 Get_Dir() const { return _dir; }
};