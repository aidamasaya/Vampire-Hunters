#pragma once

#include "Exp.h"

//�v���C���[�̌o���l���Ǘ�����N���X
class PlayerLevel {
	const int MAX_LEVEL = 99;
	int _level;
	Exp* player_Exp; //�l�N���X
public:
	PlayerLevel() {
		_level = 1;
		player_Exp = new Exp(); //������
		player_Exp->_exp = 0;
	}
	virtual ~PlayerLevel() {};

	//�o���l�l��
	void Add_Exp(Exp* e) {
		player_Exp->_exp += e->_exp;
	}
	//���x���A�b�v
	void LevelUp() {
		if (_level >= MAX_LEVEL) return;

		_level++;
	}
	//���݂̃��x��
	int Current_Level() { return _level; }
	//���݂̌o���l
	Exp* Current_Exp() { return player_Exp; }
};