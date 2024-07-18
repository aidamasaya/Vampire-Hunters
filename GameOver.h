#pragma once

#include "AbstractScene.h"

class GameOver : public AbstractScene {
    int _cnt;
    int _img;
public:
    GameOver(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~GameOver() = default;
    void Update() override;
    void Draw() const override;

    void Rainbow();
};