#include "stdafx.h"
#include "ExpAdministrator.h"

/// <summary>
/// プレイヤーレベルクラスを受け取る
/// </summary>
/// <param name="p">プレイヤーレベルクラス</param>
ExpAdministrator::ExpAdministrator(std::shared_ptr<PlayerLevel> p) {
	_player = p;
	current_Exp = 0;
	_cnt = 0;
	font = CreateFontToHandle("C:UsersmynhjDownloadsmisaki_png_2021-05-05amisaki_gothic.png", 40, 3);
	for (int i = 1; i <= 99; i++) { //レベルアップに必要な経験値量をセット
		exp_Table[i - 1] = i * 3;
	}
}

//レベルアップしたかを返す
bool ExpAdministrator::Update() {
	return Judge_Exp();
}

//レベルアップ判定
bool ExpAdministrator::Judge_Exp() {
	auto p = _player;
	if (p->Current_Level() < 99) {
		if (exp_Table[p->Current_Level()] <= p->Current_Exp()->_exp) {
			p->LevelUp();
			p->Current_Exp()->_exp = 0;
			return true;
		}
	}
	return false;
}

//経験値バー表示
void ExpAdministrator::Draw() {
	auto p = _player;
	int value = p->Current_Exp()->_exp / DRAW_SIZE;

	DrawBox(0, 0, DRAW_SIZE, 20, GetColor(255, 255, 255), FALSE);
	DrawBox(0, 0, DRAW_SIZE * p->Current_Exp()->_exp / exp_Table[p->Current_Level()], 20, GetColor(64, 255, 64), TRUE);
	DrawFormatString(1200, 1, GetColor(255, 255, 255), "LV%4d", p->Current_Level(), font);
}

//武器選択画面時の特別演出
void ExpAdministrator::MaxBar_Rainbow() {
	_cnt++;
	int r = _cnt % 120;
	int g = _cnt % 108;
	int b = _cnt % 134;
	if (_cnt % 60 > 255 || _cnt % 60 < 0) {
		_cnt = -_cnt;
	}
	DrawBox(0, 0, DRAW_SIZE, 20, GetColor(r, g, b), TRUE);
}