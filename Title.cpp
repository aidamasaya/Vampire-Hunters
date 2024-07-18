#include "stdafx.h"
#include "Title.h"
#include "GameScene.h"
#include "keyboard.h"
#include <iostream>
#include <fstream>


Title::Title(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter){
    _img = LoadGraph("C:/Users/mynhj/Downloads/スカウト展　提出データ (2)/Image/title.jpg");
    font = CreateFontToHandle("C:/Users/mynhj/Downloads/misaki_png_2021-05-05a/misaki_gothic_2nd.png", 30, 3);
}

//エンターキーが押されたパラメーターを用意してLooperクラスに渡す
void Title::Update()
{
    if (Keyboard::getPressingCount(KEY_INPUT_RETURN) == 1) {
        Parameter parameter;
        parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Easy);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
        return;
    }
}

void Title::Draw() const
{
    const char* name = "C:/Users/mynhj/source/repos/testc++/x64/Debug/save_data.txt";

    std::ifstream file(name);
    std::string line;

    if (!std::getline(file, line)) {
        std::cout << "ファイルオープンエラー" << std::endl;
    }
    else {
        std::cout << line << std::endl;

        DrawRotaGraph(Define::WIN_W / 2, Define::WIN_H / 2, 1.5, 0.0, _img, TRUE);
        DrawFormatStringToHandle(Define::CENTER_X - 120, Define::CENTER_Y - 330, GetColor(255, 0, 0), font, "Vampire Hunters");
        DrawFormatStringToHandle(Define::CENTER_X - 160, Define::CENTER_Y, GetColor(255, 0, 0), font, "Enterキーでゲームスタート");
        DrawFormatStringToHandle(Define::CENTER_X - 80, 50, GetColor(255, 255, 0), font, "$   :%d", std::stoi(line));
        file.close();
    }
}