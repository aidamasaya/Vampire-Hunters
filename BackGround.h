#pragma once

#include "IPause.h"
#include "IScroll.h"

//背景を制御するクラス
class BackGround : public IPause, public IScroll {
	bool _flag;
	Transform2D _transform;
	int _img;
public:
	BackGround();
	virtual ~BackGround() {};

	void Move_All() { _flag = true; }
	void Stop_All() { _flag = false; }

	void Scroll();
	void Draw();
};