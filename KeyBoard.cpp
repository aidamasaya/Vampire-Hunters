#include "stdafx.h"
#include "keyboard.h"

static std::unique_ptr<Keyboard> _instance;
Keyboard* Get_Instance()
{
	return _instance.get();
}

bool Keyboard::Update() {
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);
	for (int i = 0; i < Get_Instance()->KEY_NUM; i++) {
		if (nowKeyStatus[i] != 0) {
			if (Get_Instance()->_releasingCount[i] > 0) {
				Get_Instance()->_releasingCount[i] = 0;
			}
			Get_Instance()->_pressingCount[i]++;
		}
		else {
			if (Get_Instance()->_pressingCount[i] > 0) {
				Get_Instance()->_pressingCount[i] = 0;
			}
			Get_Instance()->_releasingCount[i]++;
		}
	}
	return true;
}

/*!
@brief keyCodeのキーが押されているフレーム数を返す
*/
int Keyboard::getPressingCount(int keycode) {
	if (!Get_Instance()->isAvailableCode(keycode)) {
		return -1;
	}
	return Get_Instance()->_pressingCount[keycode];
}

/*!
@brief keyCodeのキーが離されているフレーム数を返す
*/
int Keyboard::getReleasingCount(int keyCode) {
	if (!Get_Instance()->isAvailableCode(keyCode)) {
		return -1;
	}
	return Get_Instance()->_releasingCount[keyCode];
}

/*!
@brief keyCodeが有効な値か否かを返す
*/
bool Keyboard::isAvailableCode(int keyCode) {
	if (!(0 <= keyCode && keyCode < Get_Instance()->KEY_NUM)) {
		return false;
	}
	return true;
}


void Keyboard::Create()
{
	if (_instance == nullptr)
	{
		_instance = std::unique_ptr<Keyboard>(new Keyboard());
	}
}

void Keyboard::Release()
{
	_instance.release();
}