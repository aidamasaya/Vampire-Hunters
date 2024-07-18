#pragma once

#include "BaseItem.h"
#include "Health.h"
#include "PlayerHealth.h"

//回復アイテムを制御するクラス
class Health;
class PlayerHealth;
class HealItem : public BaseItem {
private:
	int _img;
	Health* item_Health;
	std::shared_ptr<BaseItem> _item; //回復量
	std::weak_ptr<PlayerHealth> player_Health; //参照変数
public:
	HealItem();
	virtual ~HealItem() {};

	bool Hit_Callback(std::shared_ptr<Collider>);

	void SetUp(Transform2D);
	void Update();
	void Draw();

	void Player_Health(std::shared_ptr<PlayerHealth> health) { player_Health = health; }
	void Action();
};