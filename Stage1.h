#pragma once

#include "PlayerController.h"
#include "PlayerHealth.h"
#include "PlayerAttack.h"
#include "PlayerAbsorb.h"
#include "PlayerDraw.h"
#include "EnemyMove.h"
#include "EnemyPattern.h"
#include "ItemManager.h"
#include "Interia.h"
#include "SelectSkill.h"
#include "ExpAdministrator.h"
#include "Pause.h"
#include "SystemManager.h"
#include "ScrollController.h"
#include "BackGround.h"

//ƒQ[ƒ€–{•Ò‚Ìˆ—
class Stage1 {
	bool _flag;
	int img_bg = LoadGraph("C:/Users/mynhj/Downloads/____.png");

	void Create_Enemy() {};
	void Create_Item() {};
	void Draw_String() {};

	void Time();
	int l;
	int i, j;
public:
	Stage1();
	virtual ~Stage1() {};

	void Enter();
	void SystemSetup();
	bool Loop();
	void Exit();
	void Draw()const;

	void Enemy_Pattern();

	int Get_Coin() { return _player->Get_Money()->Current_Money()->_coin; }

	std::shared_ptr<PlayerMove> player_Move;
	std::shared_ptr<PlayerAttack> player_Attack;
	std::shared_ptr<PlayerAbsorb> player_Absorb;
	std::shared_ptr<PlayerDraw> player_Draw;
	std::shared_ptr<PlayerController> _player;
	std::shared_ptr<Interia> _interia[10];
	std::shared_ptr<EnemyMove> enemy_Move;
	std::shared_ptr<EnemyPattern> enemy_Pattern;
	std::shared_ptr<ItemManager> item_Manager;

	std::shared_ptr<ExpAdministrator> _exp;
	std::shared_ptr<SelectSkill> _skill;
	std::shared_ptr<Pause> _pause;
	std::shared_ptr<SystemManager> _system;
	std::shared_ptr<BackGround> _back;
	std::unique_ptr<ScrollController> _scroll;
};