#pragma once

#include "stdafx.h"
#include "Singleton.h"
#include <array>

class Keyboard : public Singleton<Keyboard> {
	Keyboard() = default;
	friend Singleton<Keyboard>;
public:
	static bool Update();
	static int getPressingCount(int keycode);
	static int getReleasingCount(int keycode);

	static void Create();
	static void Release();
private:
	static const int KEY_NUM = 256;
	std::array<int, KEY_NUM> _pressingCount;
	std::array<int, KEY_NUM> _releasingCount;

	bool isAvailableCode(int keycode);
};