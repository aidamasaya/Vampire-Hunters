#include "stdafx.h"
#include "GameOver.h"
#include "GameScene.h"
#include "keyboard.h"
#include <iostream>
#include <fstream>


GameOver::GameOver(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    _cnt = 0;
    _img = LoadGraph("C:/Users/mynhj/Downloads/horror.jpg");
}

void GameOver::Update(){
    if (Keyboard::getPressingCount(KEY_INPUT_RETURN) == 1) {
        Parameter parameter;
        parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Easy);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::TitleScene, parameter, stackClear);
        return;
    }
    Rainbow();
}

void GameOver::Draw() const {
    DrawRotaGraph(Define::WIN_W / 2, Define::WIN_H / 2, 3.0, 0.0, _img, TRUE);
    DrawString(Define::WIN_W / 2 - 160, Define::WIN_H / 2, "Enterキーでタイトルに戻る", GetColor(255, 255, 255));
}

void GameOver::Rainbow() {
    _cnt++;
    int r = _cnt % 255;
    int g = _cnt % 255;
    int b = _cnt % 255;
    if (_cnt % 60 > 255 || _cnt % 60 < 0) {
        _cnt = -_cnt;
    }
    DrawString(100, 100, "リザルト", GetColor(r, g, b),TRUE);
}