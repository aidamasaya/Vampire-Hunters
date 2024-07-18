#include "stdafx.h"
#include "ResultScene.h"
#include "GameScene.h"
#include "keyboard.h"
#include <iostream>
#include <fstream>


ResultScene::ResultScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
}

void ResultScene::Update()
{
    if (Keyboard::getPressingCount(KEY_INPUT_RETURN) == 1) {
        Parameter parameter;
        parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Easy);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::TitleScene, parameter, stackClear);
        return;
    }
}

void ResultScene::Draw() const {
    DrawString(Define::CENTER_X, Define::CENTER_Y, "Enterキーでタイトルに戻る", GetColor(255, 255, 255));
}