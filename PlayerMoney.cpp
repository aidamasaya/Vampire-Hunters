#include "stdafx.h"
#include "PlayerMoney.h"

//所持金表示
void PlayerMoney::Draw() {
	DrawFormatString(Define::WIN_W - 100, 25, GetColor(255, 255, 0), "$ : %01d", _coin->_coin);
}