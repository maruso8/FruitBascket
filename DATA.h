#pragma once
#include<string>

//�f�[�^�̈��ǂݍ��ނ̂ɕK�v�ȃN���X

class DATA {
	//�f�[�^�l�@�L�ڂ���Ă��鐔����Ԃ����߂̕ϐ�
	float Value = 0;
	//�f�[�^�̖��O std::string�͂Ȃ񂩕֗���char�Ƃł��v���Ă�����
	std::string Name;
public:
	//�Z�b�^�[
	void setValue(float value);
	void setName(const char* name);
	//�Q�b�^�[
	float value();
	std::string name();

};
