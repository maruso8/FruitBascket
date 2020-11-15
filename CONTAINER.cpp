#include<cassert>
#include<stdio.h>
#include"DATA.h"
#include"CONTAINER.h"



#include<string>



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
	selectFleamImg = loadImage("�^�C�g�����ӂ�.png");
	howToPlayImg = loadImage("play.png");
	creditImg = loadImage("S.jpg");
	signalImg = loadImage("���.png");

	fadeinImg = loadImage("�t�F�[�h�C��.png");
	freamImg = loadImage("�V�ѕ��̘g�w�i.png");

	//�Q�[�����C���摜���[�h
	gameBackGroundImg = loadImage("�Q�[���w�i.png");
	playerImg = loadImage("�v���C���[.png");

	//�X�R�A�摜���[�h
	scoreImg = loadImage("sukoa.png");
	int AllNumImg = loadImage("suuzi.png");
	for (int i = 0; i < 10; i++) {
		scoreNumImg[i] = divideImage(AllNumImg, 75 * i, 0, 75, 75);
	}

	//�t���[�c�摜���[�h
	appleImg = loadImage("�����S.png");
	bananaImg = loadImage("�o�i�i.png");
	orangeImg = loadImage("�~�J��.png");
	strawberryImg = loadImage("�C�`�S.png");
	rotAppleImg = loadImage("h_ringo.png");
	rotOrangeImg = loadImage("h_mikan.png");
	clockUpImg = loadImage("t_up.png");
	clockDownImg = loadImage("t_down.png");
	shoesUpImg = loadImage("k_up.png");
	shoesDownImg = loadImage("k_down.png");

	//�X�R�A��ʃ��[�h
	scoreFreamImg = loadImage("�����L���O�g.png");
	char name[256] = { 0 };
	for (int i = 0; i < 3; i++) {
		sprintf_s(name, "%d��.png", i+1);
		rankNumImg[i] = loadImage(name);
	}

	//CONTAINER��n���Ƃ�----------------------------------------------------
	CHARACTER::setContainer(this);
	FALL::setContainer(this);
	FALL_MANEGER::setContainer(this);
	IMG::setContainer(this);
	TITLE_MANEGER::setContainer(this);
}



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
		sprintf_s(rank, "No.%d", i+1);
		fprintf(fp, "%s %d\n", rank, (int)Rank[i].value());
	}
	fclose(fp);

	delete[] Rank;
	Rank = 0;

	return 0;
}
