#pragma once

#include "stdafx.h"
#include "PlayerLevel.h"
#include "Exp.h"

#define DRAW_SIZE 1280
#define DRAW_VALUE 50

/// <summary>
/// �o���l�ƃ��x���A�b�v�̐��������N���X
/// </summary>
class ExpAdministrator {
	int font;
	int exp_Table[100];
	int current_Exp;
	std::shared_ptr<PlayerLevel> _player;
	int _cnt;

	bool Judge_Exp();
public:
	ExpAdministrator(std::shared_ptr<PlayerLevel>);

	void Add_Exp(Exp* exp) { _player->Add_Exp(exp); }

	bool Update();
	void Draw();
	void MaxBar_Rainbow();
};