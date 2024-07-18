#include "stdafx.h"
#include "PlayerMove.h"
#include "Enemy.h"
#include "keyboard.h"

PlayerMove::PlayerMove() {
	_dir.X = 1;
}

//プレイヤーのポインタを受け取る
void PlayerMove::Start(std::shared_ptr<IGameObject> player) {
	_player = player;
	_player->Dir.X = _dir.X;
}

//キー入力で向きを変える
void PlayerMove::Update() {
	auto pos = Vector2(0, 0);
	if (Keyboard::getPressingCount(KEY_INPUT_LEFT) > 0) {
		if (_dir.X != -1) _dir.X = -1;
	}if (Keyboard::getPressingCount(KEY_INPUT_RIGHT) > 0) {
		if (_dir.X != 1) _dir.X = 1;
	}

	_player->Dir.X = _dir.X;
}

void PlayerMove::Draw() {
}