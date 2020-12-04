#include<cassert>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"sound.h"

#include"DATA.h"
#include"ID_DATA.h"
#include"IMG_DATA.h"
#include"CONTAINER.h"
#include"PROCESS.h"


CONTAINER* CONTAINER::C = 0;


CONTAINER::CONTAINER() {
	//�^�C�g���Ɖ�ʂ̑傫��
	initialize("�̌��΁[��", windowWidht, windowHeight, FULLSCREEN);
	//�摜���[�h-------------------------------------------------------------
	//�^�C�g���摜���[�h
	backGroundImg = loadImage("�^�C�g�����.png");
	titleImg = loadImage("�^�C�g��.png");
	for (int i = 0; i < TotalSelect; i++) {
		sprintf_s(selectName, "%s_%d.png", "aka", i);
		selectImg[i] = loadImage(selectName);
	}
	for (int i = 0; i < 3; i++) {
		sprintf_s(selectName, "%s_%d.png", "Lv", i);
		selectLevelImg[i] = loadImage(selectName);
	}
	selectFleamImg = loadImage("�^�C�g�����ӂ�.png");
	howToPlayImg = loadImage("�V�ѕ��̘g�w�inew.png");
	creditImg = loadImage("S.jpg");
	signalImg = loadImage("���.png");

	fadeinImg = loadImage("�t�F�[�h�C��.png");
	freamImg = loadImage("�V�ѕ��̘g�w�i.png");

	//�Q�[�����C���摜���[�h
	gameBackGroundImg = loadImage("�Q�[���w�i.png");
	playerImg = loadImage("�v���C���[.png");
	playerRImg = loadImage("�v���C���[L.png");
	playerLImg = loadImage("�v���C���[R.png");


	//�X�R�A�摜���[�h
	scoreImg = loadImage("sukoa.png");
	int AllNumImg = loadImage("suuzi.png");
	for (int i = 0; i < 10; i++) {
		scoreNumImg[i] = divideImage(AllNumImg, 75 * i, 0, 75, 75);
	}

	//�X�R�A��ʃ��[�h
	scoreFreamImg = loadImage("�����L���O�g.png");
	char name[256] = { 0 };
	for (int i = 0; i < 3; i++) {
		sprintf_s(name, "%d�ʘg.png", i+1);
		rankNumImg[i] = loadImage(name);
	}

}

CONTAINER* CONTAINER::getInstance() {
	if (!C) {//C(CONTAINER)�����݂��Ȃ��Ƃ�
		//�R���e�i�����
		C = new CONTAINER;
	}

	//CONTAINER��n��
	return C;
}

CONTAINER* CONTAINER::Delete() {
	if (C) {//CONTAINER�����݂��鎞
		//delete����0�N���A
		delete C;
		C = 0;
	}
	return C;
}



int CONTAINER::LoadData(const char* filename) {
	FILE* fp = 0;
	fopen_s(&fp,filename, "r");

	//fp�����݂��Ȃ��Ƃ��͋U��Ԃ��Ă����Œ�~���Ē��ӂ��o��B#include<cassert>�Ŏg����悤�ɂȂ�B
	assert(fp != 0);
	//Data�t�@�C���̍ŏ���Img�AId�AData�̐��łȂ���΂Ȃ�Ȃ�
	for (int i = 0; i < 3; i++) {
		fscanf_s(fp, "%d", &DataNum[i]);
	}
	//scan����NumData����Deta�����ꂼ��m��
	ImgData = new IMG_DATA[DataNum[0]];
	IdData = new ID_DATA[DataNum[1]];
	Data = new DATA[DataNum[2]];
	


	//�ǂݍ��݊J�n-----------------------------------------------------------------------------------------------
	//�摜�̓ǂݍ���
	char name[256];
	int Img = 0;
	for (int i = 0; i < DataNum[0]; i++) {
		fscanf_s(fp, "%s %d", name, 256, &Img);
		ImgData[i].setName(name);
		ImgData[i].setImg(name);
	}

	//Id�̓ǂݍ���
	char Id;
	for (int i = 0; i < DataNum[1]; i++) {
		fscanf_s(fp, "%s %c", name, 256, &Id);
		IdData[i].setName(name);
		IdData[i].setId(Id);
	}

	float value;
	for (int i = 0; i < DataNum[2]; i++) {
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
	if (IdData) {
		//new data*[num]�̂悤��new��*(�|�C���^)�ō���ĂȂ��̂�delete[]��OK�B 
		delete[] IdData;
		IdData = 0;
	}
	if (ImgData) {
		//new data*[num]�̂悤��new��*(�|�C���^)�ō���ĂȂ��̂�delete[]��OK�B 
		delete[] ImgData;
		ImgData = 0;
	}
	if (rank) {
		//new data*[num]�̂悤��new��*(�|�C���^)�ō���ĂȂ��̂�delete[]��OK�B 
		delete[] rank;
		rank = 0;
	}


}

int CONTAINER::getIData(const char* name) {
	int i = 0;
	for (i = 0; i < DataNum[0]; i++) {
		if (ImgData[i].name() == name) {
			return (int)ImgData[i].img();
		}
	}
	for (i = 0; i < DataNum[2]; i++) {
		if (Data[i].name() == name) {
			return (int)Data[i].value();
		}
	}
	assert(i < DataNum[2]);
	return 0;
}


float CONTAINER::getFData(const char* name) {
	int i = 0;
	for (i = 0; i < DataNum[2]; i++) {
		if (Data[i].name() == name) {
			return Data[i].value();
		}
	}
	assert(i < DataNum[2]);
	return 0;
}

char CONTAINER::getCData(const char* name) {
	int i = 0;
	for (i = 0; i < DataNum[1]; i++) {
		if (IdData[i].name() == name) {
			return IdData[i].id();
		}
	}
	assert(i < DataNum[1]);
	return 0;
}

int CONTAINER::saveData(int Level, int score) {

	rank = new RANK[TotalRankNum];


	FILE* fp;
	fp = fopen ("score.dat", "rb");
	//fp�����݂��Ȃ��Ƃ��͋U��Ԃ��Ă����Œ�~���Ē��ӂ��o��B#include<cassert>�Ŏg����悤�ɂȂ�B
	assert(fp != NULL);
	fread(&rank[0], sizeof(RANK) * 3, 1, fp);

	fclose(fp);

	assert(rank[0].RankScore != 0);

	//��������Z�[�u�J�n
	fopen_s(&fp, "score.dat", "wb");
	assert(fp != NULL);

	//��r
	for (int i = 0; i < 3; i++) {
		if (score > rank[Level].RankScore[i]) {
			float work = rank[Level].RankScore[i];
			rank[Level].RankScore[i] = score;
			score = work;
		}
	}

	//�������݊J�n
	fwrite(&rank[0], sizeof(RANK)*3 , 1, fp);
	fclose(fp);

	return 0;
}

void CONTAINER::DeleteRank() {
	if (rank) {
		//new data*[num]�̂悤��new��*(�|�C���^)�ō���ĂȂ��̂�delete[]��OK�B 
		delete[] rank;
		rank = 0;
	}
}