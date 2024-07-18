#include "stdafx.h"
#include "SystemMain.h"
#include "Looper.h"
/*!
* @brief DXライブラリやゲームの初期処理
*/
bool SystemMain::Initialize() const {
	SetAlwaysRunFlag(TRUE);                                  //ウィンドウがノンアクティブでも実行
	SetWindowSizeChangeEnableFlag(TRUE);              //ウィンドウサイズを自由に変更できるようにする
	SetOutApplicationLogValidFlag(FALSE);             //ログ出力しない
	//	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);//フルスクリーン時に縦横比を維持する
	SetWindowText("Vampire Hunters");                  //ウィンドウタイトルを付ける
	ChangeWindowMode(TRUE);                                       //ウィンドウかフルスクリーンモードに変更                                       //ウィンドウモードに変更
	//	SetWindowSizeExtendRate(1.0);                         //ウィンドウサイズを変更したい時はここに倍率を指定する
	const int COLOR_BIT = 32;                                     //色のbit数。通常32で良いが軽くするなら16にする
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);        //ゲーム画面の解像度を設定する
	SetBackgroundColor(0, 126, 0);                          //背景色
	if (DxLib_Init()) {                                                   //DXライブラリ初期化処理
		return false;                                                     //異常終了したら即座にやめる
	}
	SetTransColor(255, 255, 255);
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

/*!
* @brief DXライブラリやゲームの終了処理
*/
void SystemMain::Finalize() const {
	DxLib_End();
}

/*!
* @brief メイン処理
*/
void SystemMain::Main() const {
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		if (!looper.loop()) {
			break;
		}

	}
}