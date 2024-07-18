#pragma once

#include "stdafx.h"
#include "Health.h"

#define WH_BAR 40

//�v���C���[�̗̑͂��Ǘ�����N���X
class PlayerHealth {
	const float MAX_HP = 999;
	float Max_HP = 0;
	Health* current_Hp; //�l�N���X
public:
	PlayerHealth(float hp) {
		if (hp > MAX_HP) return;
		current_Hp = new Health(); //������
		current_Hp->_health = hp; //�󂯎����HP�p�����[�^�[���Z�b�g
		Max_HP = current_Hp->_health; //�󂯎����HP�p�����[�^�[���ő�l�Ƃ���
	}
	virtual ~PlayerHealth() {};

	//��
	void Heal_HP(Health* hp) {
		auto Hp = hp->_health + current_Hp->_health;
		if (Hp >= Max_HP) current_Hp->_health = Max_HP;
		else current_Hp->_health += hp->_health;
	}
	//�_���[�W
	void Damage_Hp(float damage) {
		if (current_Hp->_health < 0) return;

		current_Hp->_health -= damage;
	}
	//���݂�HP
	int Current_HP() { return current_Hp->_health; }
	//UI�`��
	void Draw(Vector2);
};