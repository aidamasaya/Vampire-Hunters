#pragma once

#include "stdafx.h"
#include "AbstractScene.h"

class Title : public AbstractScene
{
    int _img;
    int font;
public:
    Title(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~Title() = default;
    void Update() override;
    void Draw() const override;
};