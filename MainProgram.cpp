#include "stdafx.h"
#include "SystemMain.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SystemMain system;
	if (system.Initialize()) {
		system.Main();
	}
	system.Finalize();
}
