#pragma once

//�v���C���[�̏ڍׂȓ������������邽�߂̃C���^�[�t�F�C�X
class IPlayerState {
public:
	virtual void Start(std::shared_ptr<IGameObject>) {};
	virtual void Update() {};
	virtual void Draw() {};
};