#include "stdafx.h"
#include "SystemMain.h"
#include "Looper.h"
/*!
* @brief DX���C�u������Q�[���̏�������
*/
bool SystemMain::Initialize() const {
	SetAlwaysRunFlag(TRUE);                                  //�E�B���h�E���m���A�N�e�B�u�ł����s
	SetWindowSizeChangeEnableFlag(TRUE);              //�E�B���h�E�T�C�Y�����R�ɕύX�ł���悤�ɂ���
	SetOutApplicationLogValidFlag(FALSE);             //���O�o�͂��Ȃ�
	//	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);//�t���X�N���[�����ɏc������ێ�����
	SetWindowText("Vampire Hunters");                  //�E�B���h�E�^�C�g����t����
	ChangeWindowMode(TRUE);                                       //�E�B���h�E���t���X�N���[�����[�h�ɕύX                                       //�E�B���h�E���[�h�ɕύX
	//	SetWindowSizeExtendRate(1.0);                         //�E�B���h�E�T�C�Y��ύX���������͂����ɔ{�����w�肷��
	const int COLOR_BIT = 32;                                     //�F��bit���B�ʏ�32�ŗǂ����y������Ȃ�16�ɂ���
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);        //�Q�[����ʂ̉𑜓x��ݒ肷��
	SetBackgroundColor(0, 126, 0);                          //�w�i�F
	if (DxLib_Init()) {                                                   //DX���C�u��������������
		return false;                                                     //�ُ�I�������瑦���ɂ�߂�
	}
	SetTransColor(255, 255, 255);
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

/*!
* @brief DX���C�u������Q�[���̏I������
*/
void SystemMain::Finalize() const {
	DxLib_End();
}

/*!
* @brief ���C������
*/
void SystemMain::Main() const {
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		if (!looper.loop()) {
			break;
		}

	}
}