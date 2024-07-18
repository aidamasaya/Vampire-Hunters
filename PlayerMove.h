#pragma once

#include "stdafx.h"
#include "IPlayerState.h"

/// <summary>
/// �v���C���[�̌����𐧌䂷��N���X
/// </summary>
class PlayerMove : public IPlayerState {
	//�����Ă����
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