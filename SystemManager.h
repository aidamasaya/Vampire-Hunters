#pragma once

#include "ExpAdministrator.h"
#include "SelectSkill.h"
#include "Pause.h"
#include "PlayerController.h"

enum StateEngine {
	Wait,
	Start,
	Run,
};

class SystemManager {
	bool _flag;
	int cnt;
	int minute;
	int frame;
	int second;
	int font;
	StateEngine _state;
	std::shared_ptr<SelectSkill> _skill;
	std::shared_ptr<ExpAdministrator> _expad;
	std::shared_ptr<Pause> _pause;
public:
	SystemManager() {};
	virtual ~SystemManager() {};

	void Setup(std::shared_ptr<SelectSkill>, std::shared_ptr<ExpAdministrator>,
		std::shared_ptr<Pause>);
	bool Main();
	void Time();
	void Draw();

	int Get_Frame() { return frame; }
	int Get_Minute() { return minute; }
	int Get_Second() { return second; }
};