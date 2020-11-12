#include<cassert>
#include<stdio.h>
#include"DATA.h"
#include"CONTAINER.h"



#include<string>



int CONTAINER::LoadData(const char* filename) {
	FILE* fp = 0;
	fopen_s(&fp, filename, "r");

	//fp�����݂��Ȃ��Ƃ��͋U��Ԃ��Ă����Œ�~���Ē��ӂ��o��B#include<cassert>�Ŏg����悤�ɂȂ�B
	assert(fp != 0);
	//deta�t�@�C���̈�s�ڂ�data���łȂ���΂����Ȃ�
	fscanf_s(fp, "%d", &NumData);

	//scan����NumData����Deta���m��
	Data = new DATA[NumData];

	//�ǂݍ��݊J�n
	char name[256];
	float value;
	for (int i = 0; i < NumData; i++) {
		//�S��float�l�œǂݍ��ށB����������炤�ꍇ�͕�����̍ő吔���w�肷��B��������󂯎��Ȃ�(�X�L�b�v����)
		//fscan_f�͑Ώۂ̎g�p�񐔁��i���ƂȂ��Ă���B�܂�scanf����ƈ��S��scanf����B
		fscanf_s(fp, "%s %f", name, 256, &value);
		Data[i].setName(name);
		Data[i].setValue(value);
	}

	fclose(fp);

	return 0;
}

CONTAINER::~CONTAINER() {
	if (Data) {
		//new data*[num]�̂悤��new��*(�|�C���^)�ō���ĂȂ��̂�delete[]��OK�B 
		delete[] Data;
		Data = 0;
	}
}


int CONTAINER::getIData(const char* name) {
	int i = 0;
	for (i = 0; i < NumData; i++) {
		if (Data[i].name() == name) {
			return (int)Data[i].value();
		}
	}
	assert(i < NumData);
	return 0;
}


float CONTAINER::getFData(const char* name) {
	int i = 0;
	for (i = 0; i < NumData; i++) {
		if (Data[i].name() == name) {
			return Data[i].value();
		}
	}
	assert(i < NumData);
	return 0;
}


int CONTAINER::saveData(const char* filename, int score) {

	FILE* fp = 0;
	//�f�[�^���������邩���߂�B
	fopen_s(&fp, filename, "r");
	//fp�����݂��Ȃ��Ƃ��͋U��Ԃ��Ă����Œ�~���Ē��ӂ��o��B#include<cassert>�Ŏg����悤�ɂȂ�B
	assert(fp != 0);
	//deta�t�@�C���̈�s�ڂ�data���łȂ���΂����Ȃ�
	fscanf_s(fp, "%d", &NumData);
	//scan����NumData����Deta���m��
	Rank = new DATA[NumData];
	//�ǂݍ��݊J�n
	char name[256];
	float value;
	for (int i = 0; i < NumData; i++) {
		//�S��int�l�œǂݍ���
		fscanf_s(fp, "%s %f", name, 256, &value);
		Rank[i].setName(name);
		Rank[i].setValue(value);
	}
	fclose(fp);



	//��������Z�[�u�J�n
	fopen_s(&fp, filename, "w");

	assert(fp != 0);

	//��r
	for (int i = 0; i < NumData; i++) {
		if (score > Rank[i].value()) {
			float work = Rank[i].value();
			Rank[i].setValue(score);
			score = work;
		}
	}
	//�������݊J�n

	fprintf(fp, "%d\n", NumData);
	char rank[256];
	for (int i = 0; i < NumData; i++) {
		sprintf_s(rank, "%s%d", "No.", i+1);
		fprintf(fp, "%s %d\n", rank, (int)Rank[i].value());
	}
	fclose(fp);

	delete[] Rank;
	Rank = 0;

	return 0;
}
