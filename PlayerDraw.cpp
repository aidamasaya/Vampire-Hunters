#include "stdafx.h"
#include "PlayerDraw.h"

//�v���C���[�̃|�C���^���󂯎��
void PlayerDraw::Start(std::shared_ptr<IGameObject> player) {
	_player = player;
	Count = 0;
	LoadDivGraph("C:/Users/mynhj/source/repos/testc++/Redball-removebg-preview.png", 6, 2, 3, 32, 32, _img);
	_size = 0.5;
}

//6�Ŋ������]����g���ă��[�v������
void PlayerDraw::Update() {
	auto p = _player.lock();
	x = p->Transform.Position.X;
	y = p->Transform.Position.Y;
	Count += 60;
	img = ((Count / x) % 6);
}

//�v���C���[�̃A�j���[�V����
void PlayerDraw::Draw() {
	auto p = _player.lock();
	DrawRotaGraph(p->Transform.Position.X, p->Transform.Position.Y, 1.5, 0.0, _img[img], TRUE, -p->Dir.X);
	//DrawCircle(p->Transform.Position.X, p->Transform.Position.Y, _size, GetColor(0, 0, 0),TRUE);
/*	DrawBox((int)p.X - p.W / 2, (int)p.Y - p.H / 2,
		(int)p.X + p.W / 2, (int)p.Y + p.H / 2,
		GetColor(64, 64, 255), TRUE);*/
}