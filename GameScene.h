#pragma once

#include  "AbstractScene.h"
#include "Stage1.h"

//�Q�[�����C��
class GameScene : public AbstractScene {
public:
	int _font;
	int _coin;
	const static char* ParameterTagStage;//�p�����[�^�̃^�O�u�X�e�[�W�v
	const static char* ParameterTagLevel;//�p�����[�^�̃^�O�u���x���v

	GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~GameScene() = default;

	void Update() override;
	void Draw() const override;
	void Save();
	bool End();
private:
	std::shared_ptr<Stage1> _stage1; //�X�e�[�W1
};