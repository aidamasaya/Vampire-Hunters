#pragma once

#include "stdafx.h"
#include "Coin.h"

//���݂̏��������Ǘ�����N���X
class PlayerMoney {
	Coin* _coin; //�l�N���X
public:
	PlayerMoney() {
		_coin = new Coin(); //������
	};
	virtual ~PlayerMoney() {};

	//�R�C���Q�b�g
	void Add_Money(Coin* coin) {
		_coin->_coin += coin->_coin;
	}
	//���݂̏�����
	Coin* Current_Money() { return _coin; }
	//UI�`��
	void Draw();
};