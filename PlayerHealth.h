#pragma once

#include "stdafx.h"
#include "Health.h"

#define WH_BAR 40

//プレイヤーの体力を管理するクラス
class PlayerHealth {
	const float MAX_HP = 999;
	float Max_HP = 0;
	Health* current_Hp; //値クラス
public:
	PlayerHealth(float hp) {
		if (hp > MAX_HP) return;
		current_Hp = new Health(); //初期化
		current_Hp->_health = hp; //受け取ったHPパラメーターをセット
		Max_HP = current_Hp->_health; //受け取ったHPパラメーターを最大値とする
	}
	virtual ~PlayerHealth() {};

	//回復
	void Heal_HP(Health* hp) {
		auto Hp = hp->_health + current_Hp->_health;
		if (Hp >= Max_HP) current_Hp->_health = Max_HP;
		else current_Hp->_health += hp->_health;
	}
	//ダメージ
	void Damage_Hp(float damage) {
		if (current_Hp->_health < 0) return;

		current_Hp->_health -= damage;
	}
	//現在のHP
	int Current_HP() { return current_Hp->_health; }
	//UI描画
	void Draw(Vector2);
};