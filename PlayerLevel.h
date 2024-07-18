#pragma once

#include "Exp.h"

//プレイヤーの経験値を管理するクラス
class PlayerLevel {
	const int MAX_LEVEL = 99;
	int _level;
	Exp* player_Exp; //値クラス
public:
	PlayerLevel() {
		_level = 1;
		player_Exp = new Exp(); //初期化
		player_Exp->_exp = 0;
	}
	virtual ~PlayerLevel() {};

	//経験値獲得
	void Add_Exp(Exp* e) {
		player_Exp->_exp += e->_exp;
	}
	//レベルアップ
	void LevelUp() {
		if (_level >= MAX_LEVEL) return;

		_level++;
	}
	//現在のレベル
	int Current_Level() { return _level; }
	//現在の経験値
	Exp* Current_Exp() { return player_Exp; }
};