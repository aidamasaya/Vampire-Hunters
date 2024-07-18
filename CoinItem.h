#pragma once

#include "Coin.h"
#include "BaseItem.h"
#include "PlayerMoney.h"

//コインを制御するクラス
class Coin;
class PlayerMoney;
class CoinItem : public BaseItem {
	int _img;
	Coin* item_coin; //獲得コイン
	std::weak_ptr<PlayerMoney> player_Money;//参照変数
public:
	CoinItem();
	virtual ~CoinItem() {};

	bool Hit_Callback(std::shared_ptr<Collider>);

	void SetUp(Transform2D);
	void Update();
	void Draw();

	void Player_Money(std::shared_ptr<PlayerMoney> money) { player_Money = money; }
	void Action();
};