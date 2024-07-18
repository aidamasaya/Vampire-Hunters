#pragma once

#include  "AbstractScene.h"
#include "Stage1.h"

//ゲームメイン
class GameScene : public AbstractScene {
public:
	int _font;
	int _coin;
	const static char* ParameterTagStage;//パラメータのタグ「ステージ」
	const static char* ParameterTagLevel;//パラメータのタグ「レベル」

	GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~GameScene() = default;

	void Update() override;
	void Draw() const override;
	void Save();
	bool End();
private:
	std::shared_ptr<Stage1> _stage1; //ステージ1
};