#pragma once

#include "IPause.h"
#include "IScroll.h"

//�w�i�𐧌䂷��N���X
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