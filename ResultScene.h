#pragma once


#include "AbstractScene.h"

class ResultScene : public AbstractScene {
    int _cnt;
public:
    ResultScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~ResultScene() = default;
    void Update() override;
    void Draw() const override;

    void Rainbow() {};
};