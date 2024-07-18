#pragma once

#include "stdafx.h"
#include "IPlayerState.h"

//�A�C�e�����z������N���X�A�C���^�[�t�F�C�X������
class PlayerAbsorb : public IPlayerState, public IGameObject {
	std::shared_ptr<IGameObject> _player;
public:
	PlayerAbsorb() {};
	virtual ~PlayerAbsorb() {};

	void Start(std::shared_ptr<IGameObject>);
	void Update();
	void Draw();

	void Calc(std::shared_ptr<IGameObject>);

	bool Hit_Callback(std::shared_ptr<Collider> target);
};