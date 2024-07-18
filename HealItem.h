#pragma once

#include "BaseItem.h"
#include "Health.h"
#include "PlayerHealth.h"

//�񕜃A�C�e���𐧌䂷��N���X
class Health;
class PlayerHealth;
class HealItem : public BaseItem {
private:
	int _img;
	Health* item_Health;
	std::shared_ptr<BaseItem> _item; //�񕜗�
	std::weak_ptr<PlayerHealth> player_Health; //�Q�ƕϐ�
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