#include "stdafx.h"
#include "SystemManager.h"

void SystemManager::Setup(std::shared_ptr<SelectSkill> skill, std::shared_ptr<ExpAdministrator> exp, std::shared_ptr<Pause> pa) {
	_pause = pa;
	_skill = skill;
	_expad = exp;
	_state = StateEngine::Wait;
	cnt = 0;
	minute = 0;
	second = 0;
	frame = 0;
	_flag = true;
	font = CreateFontToHandle("C:/Users/mynhj/Downloads/misaki_png_2021-05-05a/misaki_gothic_2nd.png", 30, 3);
}

#include "stdafx.h"

bool SystemManager::Main() {
	switch (_state) {
	case StateEngine::Wait:
		_expad->Draw();
		Time();

		if (_expad->Update() == false) return true;
		_state = StateEngine::Start;
		break;
	case StateEngine::Start:
		_pause->Stop_All();
		_skill->Start();
		_state = StateEngine::Run;
		break;
	case StateEngine::Run:
		_flag = false;
		_expad->MaxBar_Rainbow();

		if (_skill->Main() == true) return true;
		_pause->Move_All();
		_flag = true;
		_state = StateEngine::Wait;
		break;
	}
	return true;
}

void SystemManager::Time() {
	if (_pause->Update() == 0) _flag = false;
	if (_pause->Update() == 1) _flag = true;

	if (_flag == true) {
		cnt++;
		frame = cnt % 60;
		second = cnt / 60;
		// •¶Žš—ñ‚ÅŽžŒv‚Ì‚æ‚¤‚È•\Ž¦
		if (second >= 60) {
			cnt = 0;
			second = 0;
			minute++;
		}
	}
	else {
		DrawFormatStringToHandle(Define::CENTER_X - 50, Define::CENTER_Y - 50, GetColor(255, 255, 255), font, "PAUSE");
	}
}

void SystemManager::Draw() {
	DrawFormatStringToHandle(Define::WIN_W / 2 - 50, 25, GetColor(255, 255, 255), font, "%02d:%02d", minute, second);
}