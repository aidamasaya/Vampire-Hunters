#pragma once

//�|�[�Y�C���^�[�t�F�C�X���p�����ă|�[�Y��������������
class IPause {
public:
	IPause() {};
	virtual ~IPause() {};

	virtual void Stop_All() = 0; //�|�[�Y
	virtual void Move_All() = 0; //�|�[�Y����
};