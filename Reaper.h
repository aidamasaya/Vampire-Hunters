#pragma once

#include "Enemy.h"

//�G�̃T�u�N���X�B�Q�[���������I��������
class Reaper : public Enemy {
public:
	Reaper() {};
	virtual ~Reaper() {};
	bool Hit_Callback(std::shared_ptr<Collider>);
};