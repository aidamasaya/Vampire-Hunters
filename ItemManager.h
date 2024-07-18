#pragma once

#include "IScroll.h"
#include "ItemPool.h"
#include "ItemData.h"

//�A�C�e���Ǘ��N���X���N�G�X�g�ɉ������A�C�e����񋟂���
class ItemManager : public IPause, public IScroll {
	bool _flag;
	std::shared_ptr<ItemPool> item_Pool; //�A�C�e���v�[��
	std::shared_ptr<ExpAdministrator> _exp; //�Q�ƕϐ�

	std::vector<std::shared_ptr<BaseItem>> Items;//�X�N���[��������A�C�e�����i�[
public:
	ItemManager();
	virtual ~ItemManager() {};

	void Set_Admini(std::shared_ptr<ExpAdministrator> exp) { _exp = exp; }

	void SetUp_Exp(Transform2D pos);
	void SetUp_Coin(Transform2D pos);
	void SetUp_Heal(Transform2D pos);

	void Run();
	void Erase();

	void Move_All() { _flag = true; }
	void Stop_All() { _flag = false; }

	void Scroll();
};