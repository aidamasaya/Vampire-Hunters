#include "stdafx.h"
#include "GameScene.h"
#include "keyboard.h"
#include "Title.h"
#include "FontData.h"
#include <iostream>
#include <fstream>

#include <random>

const char* GameScene::ParameterTagStage = "ParameterTagStage";//�p�����[�^�̃^�O�u�X�e�[�W�v
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//�p�����[�^�̃^�O�u���x���v

GameScene::GameScene(IOnSceneChangedListener* impl_, const Parameter& parameter_) : AbstractScene(impl_, parameter_)
{
	ColliderManager::Create();

	_stage1 = std::make_unique<Stage1>();
	_stage1->Enter();
	_font = CreateFontToHandle("C:/Users/mynhj/Downloads/misaki_png_2021-05-05a/misaki_gothic_2nd.png", 30, 3);
}

//�Q�[�����[�v
void GameScene::Update() {
	ColliderManager::Run();

	//�Z�[�u�f�[�^�t�@�C�����J��
	const char* name = "C:/Users/mynhj/source/repos/testc++/x64/Debug/save_data.txt";
	std::ifstream file(name);
	std::string line;

	if (!std::getline(file, line)) {
		std::cout << "�t�@�C���I�[�v���G���[" << std::endl;
	}
	else {
		_coin = std::stoi(line);
	}

	if (!_stage1->Loop()) { //�Q�[�����[�v
		if (End() == true) {
			_coin += _stage1->Get_Coin();
			Save(); //�f�[�^���X�V
			Parameter parameter;
			parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Easy);
			const bool stackClear = false;
			ColliderManager::Release();
			_implSceneChanged->onSceneChanged(eScene::TitleScene, parameter, stackClear);
			return;
		}
	}
}

//�f�[�^�̃Z�[�u
void GameScene::Save() {
	const char* name = "C:/Users/mynhj/source/repos/testc++/x64/Debug/save_data.txt"; // save_data.dat(�Z�[�u�f�[�^�t�@�C��)
	std::ofstream ofs(name);
	if (!ofs) {
		std::cout << "�t�@�C���I�[�v���G���[" << std::endl;
	}
	else {
		ofs << _coin << std::endl;
		ofs.close();
	}
}

bool GameScene::End() {
	if (Keyboard::getPressingCount(KEY_INPUT_RETURN) > 0) {
		return true;
	}
	else {
		DrawFormatStringToHandle(Define::WIN_W / 2 - 50, Define::CENTER_Y / 2, GetColor(255, 255, 255), _font, "GameOver");
		return false;
	}
}

void GameScene::Draw() const {
}