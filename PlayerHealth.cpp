#include "stdafx.h"
#include "PlayerHealth.h"

//HPƒo[•\Ž¦
void PlayerHealth::Draw(Vector2 pos) {
	if (current_Hp->_health <= 0) return;

	auto x = pos.X;
	auto y = pos.Y;
	DrawBox(x - 20, y + 60, x - 20 + WH_BAR, y + 40, GetColor(255, 64, 64), FALSE);
	DrawBox(x - 20, y + 60, x - 20 + WH_BAR * current_Hp->_health / Max_HP, y + 40, GetColor(255, 64, 64), TRUE);

	//DrawFormatString(x - 40, y - 108, GetColor(255, 255, 255), "HP :  %.0f", p->Get_Struct()._hp);
}