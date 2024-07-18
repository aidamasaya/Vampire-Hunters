#pragma once

#include "stdafx.h"
#include "Coin.h"

//現在の所持金を管理するクラス
class PlayerMoney {
	Coin* _coin; //値クラス
public:
	PlayerMoney() {
		_coin = new Coin(); //初期化
	};
	virtual ~PlayerMoney() {};

	//コインゲット
	void Add_Money(Coin* coin) {
		_coin->_coin += coin->_coin;
	}
	//現在の所持金
	Coin* Current_Money() { return _coin; }
	//UI描画
	void Draw();
};