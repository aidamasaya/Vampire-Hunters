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
    _sceneStack.push(std::make_shared<Title>(this, parameter)); //�^�C�g����ʃV�[���������push
}
/*!
@brief �X�^�b�N�̃g�b�v�̃V�[���̏���������
*/
bool Looper::loop() {
    Keyboard::Update();
    _sceneStack.top()->Update();    //�X�^�b�N�̃g�b�v�̃V�[�����X�V
    _sceneStack.top()->Draw();      //�X�^�b�N�̃g�b�v�̃V�[����`��
    _fps.draw();
    _fps.wait();
    return true;
}

/*!
@brief �V�[���ύX(�e�V�[������R�[���o�b�N�����)
@param scene �ύX����V�[����enum
@param parameter �O�̃V�[����������p���p�����[�^
@param stackClear ���݂̃V�[���̃X�^�b�N���N���A���邩
*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) {
    if (stackClear) {//�X�^�b�N�N���A�Ȃ�
        while (!_sceneStack.empty()) {//�X�^�b�N��S���|�b�v����(�X�^�b�N����ɂ���)
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
        ERR("����͂��̂Ȃ��V�[�����Ă΂�܂���");
        break;
    }
}