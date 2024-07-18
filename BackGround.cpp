#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround() {
	_flag = true;
	_img = LoadGraph("C:/Users/mynhj/Downloads/スカウト展　提出データ (2)/Image/GreenField.jpg");
	_transform.Position = Vector2(Define::CENTER_X, Define::CENTER_Y);
}

void BackGround::Scroll() {
	if (_flag == false) return;
}

void BackGround::Draw() {
	DrawRotaGraph(_transform.Position.X, _transform.Position.Y, 3.0, 0.0, _img, TRUE);
}