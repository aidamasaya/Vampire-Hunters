#pragma once

#include "Enemy.h"

//敵のサブクラス。ゲームを強制終了させる
class Reaper : public Enemy {
public:
	Reaper() {};
	virtual ~Reaper() {};
	bool Hit_Callback(std::shared_ptr<Collider>);
};