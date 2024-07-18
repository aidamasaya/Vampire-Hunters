#include "stdafx.h"
#include "Stage1.h"
#include "SkillData.h"
#include "EnemyData.h"

Stage1::Stage1() {
	i = 0;
	j = 0;
	l = true;
}

//全オブジェクトのインスタンス＆初期化
void Stage1::Enter() {
	player_Attack = std::make_shared<PlayerAttack>();
	player_Move = std::make_shared<PlayerMove>();
	player_Absorb = std::make_shared<PlayerAbsorb>();
	player_Draw = std::make_shared<PlayerDraw>();
	_player = std::make_shared<PlayerController>();
	_player->Attach_Subclass(player_Attack);
	_player->Attach_Subclass(player_Move);
	_player->Attach_Subclass(player_Absorb);
	_player->Attach_Subclass(player_Draw);
	_player->Start();
	_player->Transform.Position = Vector2(Define::WIN_W / 2, Define::WIN_H / 2);

	_back = std::make_shared<BackGround>();
	item_Manager = std::make_shared<ItemManager>();
	Transform2D posi;
	posi.Position = Vector2(GetRand(Define::CENTER_X), GetRand(Define::CENTER_Y));
	item_Manager->SetUp_Coin(posi);
	posi.Position = Vector2(GetRand(Define::CENTER_X), GetRand(Define::CENTER_Y));
	item_Manager->SetUp_Heal(posi);
	_scroll = std::make_unique<ScrollController>();
	for (int i = 0; i < 10; i++) {
		_interia[i] = std::make_shared<Interia>(item_Manager);
		_interia[i]->Setup();
		_scroll->Add_Component(_interia[i]);
	}
	enemy_Move = std::make_shared<EnemyMove>(_player, item_Manager);
	enemy_Pattern = std::make_shared<EnemyPattern>(enemy_Move);
	SystemSetup();
	_scroll->Add_Component(enemy_Move);
	_scroll->Add_Component(item_Manager);
	_scroll->Add_Component(_back);
}

void Stage1::SystemSetup() {
	_pause = std::make_shared<Pause>();
	_pause->Add_Component(_back);
	_pause->Add_Component(_player);
	_pause->Add_Component(item_Manager);
	_pause->Add_Component(enemy_Move);
	_pause->Add_Component(enemy_Pattern);
	for (int i = 0; i < 10; i++) {
		_pause->Add_Component(_interia[i]);
	}
	_skill = std::make_shared<SelectSkill>(player_Attack);
	_skill->Setup();
	_exp = std::make_shared<ExpAdministrator>(_player->Get_Level());
	item_Manager->Set_Admini(_exp);
	_system = std::make_shared<SystemManager>();
	_system->Setup(_skill, _exp, _pause);
}

/// <summary>
/// ゲームループ
/// </summary>
/// <returns>falseでゲーム終了</returns>
bool Stage1::Loop() {
	if (!_player->isDeath()) return false;

	_scroll->Move();
	_back->Draw();
	Time();
	for (int i = 0; i < 10; i++) _interia[i]->Draw();
	enemy_Move->Run();
	item_Manager->Run();
	_player->Update();
	_player->Draw();

	Enemy_Pattern();
	if (_system->Main() == false) return false;
	Draw();
	return true;
}

//指定時間ごとに敵を出現させる
void Stage1::Enemy_Pattern() {
	enemy_Pattern->Main();

	if (_system->Get_Minute() == 1) {
		enemy_Pattern->Clean();
		item_Manager->Erase();
	}
	if (_system->Get_Minute() == 1 && _system->Get_Second() == 3) {
		enemy_Pattern->Death();
	}
}


void Stage1::Exit() {
}

void Stage1::Time() {
}

//UI描画
void Stage1::Draw() const {
	_system->Draw();
}