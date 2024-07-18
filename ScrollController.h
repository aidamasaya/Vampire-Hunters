#pragma once

#include "stdafx.h"
#include "IScroll.h"

//ÉXÉNÉçÅ[Éã
class ScrollController {
	bool _flag;
	std::vector<std::shared_ptr<IScroll>> _scrolls;
public:
	ScrollController() {};
	virtual ~ScrollController() {};

	void Move();
	void Add_Component(std::shared_ptr<IScroll> scroll) { _scrolls.push_back(scroll); }
};