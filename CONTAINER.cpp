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
	initialize("FuruitBascket", windowWidht,windowHeight, FULLSCREEN);
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
	levelSelectFleamImg = loadImage("���x���I��g.png");
	signalImg = loadImage("���.png");

	for (int i = 0; i < TotalHowTo; i++) {
		sprintf_s(selectName, "%s_%d.png", "�V�ѕ�", i);
		HowToPlayImg[i] = loadImage(selectName);
	}
	CreditImg = loadImage("�N���W�b�g.png");


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
	char Scorename[256] = { 0 };
	for (int i = 0; i < 3; i++) {
		sprintf_s(Scorename, "%d�ʘg.png", i+1);
		rankNumImg[i] = loadImage(Scorename);
	}



	rank = new RANK[TotalRankNum];



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
	
	
	fopen_s(&fp, "data/Data.bin", "rb");

	//fp�����݂��Ȃ��Ƃ��͋U��Ԃ��Ă����Œ�~���Ē��ӂ��o��B#include<cassert>�Ŏg����悤�ɂȂ�B
	assert(fp != 0);

	//dat�ɂ���f�[�^��FallData�ɓ����
	fread(&FallData, sizeof(FALL_DATA), 1, fp);
	fclose(fp);



	//scan����NumData����Deta�����ꂼ��m��
	ImgData = new IMG_DATA[FallData.NumImgData];
	IdData = new ID_DATA[FallData.NumIdData];
	Data = new DATA[FallData.NumData];

	//�ǂݍ��݊J�n-----------------------------------------------------------------------------------------------
	//�摜�̓ǂݍ���
	for (int i = 0; i < FallData.NumImgData; i++) {
		ImgData[i].setName(FallData.ImgName[i].c_str());
		ImgData[i].setImg(FallData.ImgName[i].c_str());
	}

	//Id�̓ǂݍ���
	for (int i = 0; i < FallData.NumIdData; i++) {
		IdData[i].setName(FallData.IdName[i].c_str());
		IdData[i].setId(FallData.Id[i]);
	}

	//Data�̓ǂݍ���
	for (int i = 0; i < FallData.NumData; i++) {

		Data[i].setName(FallData.FallDataName[i].c_str());
		Data[i].setValue(FallData.FallData[i]);
	}


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
	for (i = 0; i < FallData.NumImgData; i++) {
		if (ImgData[i].name() == name) {
			return (int)ImgData[i].img();
		}
	}
	for (i = 0; i < FallData.NumData; i++) {
		if (Data[i].name() == name) {
			return (int)Data[i].value();
		}
	}
	assert(i < FallData.NumData);
	return 0;
}


float CONTAINER::getFData(const char* name) {



	int i = 0;
	for (i = 0; i < FallData.NumData; i++) {
		if (Data[i].name() == name) {
			return Data[i].value();
		}
	}
	assert(i < FallData.NumData);
	return 0;
}

char CONTAINER::getCData(const char* name) {



	int i = 0;
	for (i = 0; i < FallData.NumIdData; i++) {
		if (IdData[i].name() == name) {
			return IdData[i].id();
		}
	}
	assert(i < FallData.NumIdData);
	return 0;
}

int CONTAINER::saveData(int Level, int score) {



	FILE* fp;
	fp = fopen ("data/score.dat", "rb");
	//fp�����݂��Ȃ��Ƃ��͋U��Ԃ��Ă����Œ�~���Ē��ӂ��o��B#include<cassert>�Ŏg����悤�ɂȂ�B
	assert(fp != NULL);
	fread(&rank[0], sizeof(RANK) * 3, 1, fp);

	fclose(fp);

	assert(rank[0].RankScore != 0);

	//��������Z�[�u�J�n
	fopen_s(&fp, "data/score.dat", "wb");
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
