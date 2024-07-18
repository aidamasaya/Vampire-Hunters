#include "stdafx.h"
#include "ExpAdministrator.h"

/// <summary>
/// �v���C���[���x���N���X���󂯎��
/// </summary>
/// <param name="p">�v���C���[���x���N���X</param>
ExpAdministrator::ExpAdministrator(std::shared_ptr<PlayerLevel> p) {
	_player = p;
	current_Exp = 0;
	_cnt = 0;
	font = CreateFontToHandle("C:UsersmynhjDownloadsmisaki_png_2021-05-05amisaki_gothic.png", 40, 3);
	for (int i = 1; i <= 99; i++) { //���x���A�b�v�ɕK�v�Ȍo���l�ʂ��Z�b�g
		exp_Table[i - 1] = i * 3;
	}
}

//���x���A�b�v��������Ԃ�
bool ExpAdministrator::Update() {
	return Judge_Exp();
}

//���x���A�b�v����
bool ExpAdministrator::Judge_Exp() {
	auto p = _player;
	if (p->Current_Level() < 99) {
		if (exp_Table[p->Current_Level()] <= p->Current_Exp()->_exp) {
			p->LevelUp();
			p->Current_Exp()->_exp = 0;
			return true;
		}
	}
	return false;
}

//�o���l�o�[�\��
void ExpAdministrator::Draw() {
	auto p = _player;
	int value = p->Current_Exp()->_exp / DRAW_SIZE;

	DrawBox(0, 0, DRAW_SIZE, 20, GetColor(255, 255, 255), FALSE);
	DrawBox(0, 0, DRAW_SIZE * p->Current_Exp()->_exp / exp_Table[p->Current_Level()], 20, GetColor(64, 255, 64), TRUE);
	DrawFormatString(1200, 1, GetColor(255, 255, 255), "LV%4d", p->Current_Level(), font);
}

//����I����ʎ��̓��ʉ��o
void ExpAdministrator::MaxBar_Rainbow() {
	_cnt++;
	int r = _cnt % 120;
	int g = _cnt % 108;
	int b = _cnt % 134;
	if (_cnt % 60 > 255 || _cnt % 60 < 0) {
		_cnt = -_cnt;
	}
	DrawBox(0, 0, DRAW_SIZE, 20, GetColor(r, g, b), TRUE);
}