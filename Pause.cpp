#include "stdafx.h"
#include "Pause.h"
#include "keyboard.h"

//エスケープボタンでポーズ、リターンで解除
int Pause::Update() {
	if (Keyboard::getPressingCount(KEY_INPUT_ESCAPE) == 1) {
		Stop_All();
		Mono();
		return 0;
	}if (Keyboard::getPressingCount(KEY_INPUT_RETURN) == 1) {
		Move_All();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		return 1;
	}
	return 2;
}

//オブジェクトをポーズ
void Pause::Stop_All() {
	for (auto c : _components) {
		c->Stop_All();
	}
}
//オブジェクトのポーズ解除
void Pause::Move_All() {
	for (auto c : _components) {
		c->Move_All();
	}
}
//ポーズインターフェイス追加
void Pause::Add_Component(std::shared_ptr<IPause> c) {
	_components.push_back(c);
}
//ポーズ時に画面の色をブレンドする
void Pause::Mono() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 210);
	DrawFillBox(0, 0, Define::WIN_W, Define::WIN_H, GetColor(10, 10, 10));
}