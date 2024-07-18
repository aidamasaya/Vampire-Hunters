#pragma once

#pragma once

#include "IPause.h"

//�|�[�Y�C���^�[�t�F�C�X�𐧌䂷��N���X
class Pause : public IPause {
	bool flag = false;
	std::vector<std::shared_ptr<IPause>> _components;
public:
	Pause() {};
	virtual ~Pause() {};

	void Add_Component(std::shared_ptr<IPause>);

	int Update();
	void Mono();

	void Stop_All() override;
	void Move_All() override;
};