#pragma once

#include "IOnSceneChangedListener.h"
#include "Parameter.h"

class IOnSceneChangedListener;

class AbstractScene {
protected:
    IOnSceneChangedListener* _implSceneChanged;
public:
    AbstractScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~AbstractScene() = default;
    virtual void Update() = 0;
    virtual void Draw() const = 0;
};