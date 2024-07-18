#pragma once

#include "stdafx.h"
#include "IPlayerState.h"

//�v���C���[�̊G�𐧌䂷��N���X
class PlayerDraw : public IPlayerState {
	int img;
	int x, y;
	int _img[6];
	int _size;
	int Count;
	int _cnt;
	std::weak_ptr<IGameObject> _player;
public:
	PlayerDraw() {};
	virtual ~PlayerDraw() {};

	void Start(std::shared_ptr<IGameObject>);
	void Update();
	void Draw();
};