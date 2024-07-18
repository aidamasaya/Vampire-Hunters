#pragma once

#include <stack>
#include <memory>
#include "AbstractScene.h"
#include "IOnSceneChangedListener.h"
#include "Title.h"
#include "GameOver.h"
#include "ResultScene.h"
#include "fps.h"

class Looper : public IOnSceneChangedListener
{
public:
    Looper();
    ~Looper() = default;
    bool loop();
    void onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) override;
private:
    std::stack<std::shared_ptr<AbstractScene>> _sceneStack; //シーンのスタック
    Fps _fps;
};