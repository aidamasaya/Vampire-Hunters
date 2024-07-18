#include "stdafx.h"
#include "Looper.h"
#include "keyboard.h"
#include "Error.h"
#include "GameScene.h"
#include "ItemData.h"
#include "EnemyData.h"
#include "SkillData.h"
#include "Macro.h"

Looper::Looper() {
    ItemData::Create();
    ItemData::Set_up();
    SkillData::Create();
    SkillData::Set_up();
    EnemyData::Create();
    EnemyData::Set_up();
    Keyboard::Create();

    Parameter parameter;
    _sceneStack.push(std::make_shared<Title>(this, parameter)); //タイトル画面シーンを作ってpush
}
/*!
@brief スタックのトップのシーンの処理をする
*/
bool Looper::loop() {
    Keyboard::Update();
    _sceneStack.top()->Update();    //スタックのトップのシーンを更新
    _sceneStack.top()->Draw();      //スタックのトップのシーンを描画
    _fps.draw();
    _fps.wait();
    return true;
}

/*!
@brief シーン変更(各シーンからコールバックされる)
@param scene 変更するシーンのenum
@param parameter 前のシーンから引き継ぐパラメータ
@param stackClear 現在のシーンのスタックをクリアするか
*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) {
    if (stackClear) {//スタッククリアなら
        while (!_sceneStack.empty()) {//スタックを全部ポップする(スタックを空にする)
            _sceneStack.pop();
        }
    }
    switch (scene) {
    case TitleScene:
        _sceneStack.push(std::make_shared<Title>(this, parameter));
        break;
    case Game:
        _sceneStack.push(std::make_shared<GameScene>(this, parameter));
        break;
    case Gameover:
        _sceneStack.push(std::make_shared<GameOver>(this, parameter));
        break;
    case Result:
        _sceneStack.push(std::make_shared<ResultScene>(this, parameter));
        break;
    default:
        ERR("あるはずのないシーンが呼ばれました");
        break;
    }
}