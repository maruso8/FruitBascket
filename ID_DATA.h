#pragma once
#include<string>

//�f�[�^�̈��ǂݍ��ނ̂ɕK�v�ȃN���X

class ID_DATA {
	//�f�[�^�̖��O std::string�͂Ȃ񂩕֗���char�Ƃł��v���Ă�����
	std::string Name;
	//Id�̖��O�@furuit�̂��߂ɒǉ�
	char Id = 0;
public:
	//�Z�b�^�[
	void setName(const char* name);
	void setId(const char id);
	//�Q�b�^�[
	std::string name();
	char id();

};
