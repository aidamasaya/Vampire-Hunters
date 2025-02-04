#include "stdafx.h"
#include "Error.h"

using namespace std;

void Error::finish(const char* errorMessage, LPCTSTR lpszFuncName, int lineN) {
	char funcName[1024];
	printfDx("異常が発生しました \n%s\n%s(%d)"
		, errorMessage
		, funcName
		, lineN
	);
	while (!ProcessMessage()) {
		ClearDrawScreen();
		ScreenFlip();
	}
	DxLib_End();
	exit(99);
}