#pragma once
#include<string>

//�f�[�^�̈��ǂݍ��ނ̂ɕK�v�ȃN���X

class IMG_DATA {
	
	//�f�[�^�̖��O std::string�͂Ȃ񂩕֗���char�Ƃł��v���Ă�����
	std::string Name;
	//�摜�ԍ��@img�̂��߂ɒǉ�
	int Img = 0;
public:
	//�Z�b�^�[
	void setName(const char* name);
	void setImg(const char* name);
	//�Q�b�^�[
	std::string name();
	int img();

};