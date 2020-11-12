#pragma once
#include<stdio.h>
#include"graphic.h"
#include"framework.h"
#include"graphic.h"
#include"CHARACTER.h"
#include"FALL.h"
#include"FALL_MANEGER.h"
#include"IMG.h"
#include"TITLE_MANEGER.h"


#include<string>



//DATA�̒l������Ƃ���B

class CONTAINER {

	class DATA* Data = 0;
	class DATA* Rank = 0;
	int NumData = 0;

public:

	~CONTAINER();
	//�t�@�C������f�[�^��ǂݍ���
	int LoadData(const char* filename);
	//�f�[�^��int�l�Ŏ擾
	int getIData(const char* name);
	//�f�[�^��float�l�Ŏ擾
	float getFData(const char* name);

	//�t�@�C���Ƀf�[�^����������
	int saveData(const char* filename, int score);

	//SYSTEM
	const int windowWidht = 1920;//1920
	const int windowHeight = 1080;//1080
	const int fallCnt = 100;
	int fadeinImg = 0;
	float fadePx = 0.0f;
	float fadePy = 0.0f;
	COLOR fadeColor = COLOR(1, 1, 1, 0);
	float fadeDecayAlpha = 1.0f / 50.0f;

	//BACK_GROUND
	int backGroundImg = 0;
	int gameBackGroundImg = 0;
	const float backGroundPx = 0.0f;
	const float backGroundPy = 0.0f;
	const int backGroundNum = 1;


	//TITLE
	int titleImg = 0;
	const float titlePx = 1200.0f;
	const float titlePy = 0.0f;
	const int titleNum = 1;

	//SELECT
	int selectImg[4] = { 0,0,0,0 };
	int selectFleamImg = 0;
	char selectName[256];
	const int TotalSelect = 4;
	const float selectPx = 50.0f;
	const float selectPy = 400.0f;
	const float selectHeight = 175.0f;
	const COLOR selectColor = COLOR(1.0f, 1.0f, 1.0f, 0.5f);
	const int selectNum = 4;

	//fream
	int freamImg = 0;
	const float freamPx=500.0f;
	const float freamPy=50.0f;
	const int freamNum = 1;

	//HowToPlay
	int howToPlayImg = 0;
	const float howToPlayPx = 500.0f;
	const float howToPlayPy = 50.0f;
	const int howToPlayNum = 1;

	//CREDIT
	int creditImg = 0;
	const float creditPx = 500.0f;
	const float creditPy = 500.0f;
	const int creditNum = 1;

	//SIGNAL
	int signalImg = 0;
	const float signalPx = 650.0f;
	const float signalPy = 425.0f;
	const int signalNum = 1;

	//GAME_PLAY
	int scoreImg[10] = { 0 };
	const float scorePx = 225.0f;
	const float scorePy = 0.0f;
	const float timePx = 0.0f;
	const float timePy = 75.0f;

	//FALL_FRUIT&ITEM
	const float fallRadius = 50.0f;//75

	//PLAYER
	int playerImg = 0;
	const float playerPx = 500.0f;
	const float playerPy = 930.0f;
	const float playerAdsSpeed = 10.0f;
	const float playerWidht = 70.0f;
	const float playerHeight = 111.0f;

	const float playerHitTop = 0.0f;//15
	const float playerHitBottom = 10.0f;//27
	const float playerHitLeft =  50.0f;//78
	const float playerHitRight = 50.0f;//74

	//FALL_APPLE
	int appleImg = 0;
	const char appleId= 'a';
	const int NumApple = 7;
	const float appleAdsSpeed = 3.0f;
	const float appleAlpha =  0.0f;
	const int appleScore = 50;

	//FALL_STRAWBERRY
	int strawberryImg = 0;
	const char strawberryId = 'b';
	const int NumStrawberry = 7;
	const float strawberryAdsSpeed = 4.0f;
	const float strawberryAlpha = 0.0f;
	const int strawberryScore = 100;

	//FALL_ORANGE
	int orangeImg = 0;
	const char orangeId = 'c';
	const int NumOrange = 7;
	const float orangeAdsSpeed = 5.0f;
	const float orangeAlpha = 0.0f;
	const int orangeScore = 200;

	//FALL_BANANA
	int bananaImg = 0;
	const char bananaId = 'd';
	const int NumBanana = 7;
	const float bananaAdsSpeed = 6.0f;
	const float bananaAlpha = 0.0f;
	const int bananaScore = 300;

	//FALL_ROT_APPLE
	int rotAppleImg = 0;
	const char rotAppleId = 'e';
	const int NumRotApple = 7;
	const float rotAppleAdsSpeed = 5.0f;
	const float rotAppleAlpha = 0.0f;
	const int rotAppleScore = -100;

	//FALL_ROT_ORANGE
	int rotOrangeImg = 0;
	const char rotOrangeId = 'f';
	const int NumRotOrange = 7;
	const float rotOrangeAdsSpeed = 5.0f;
	const float rotOrangeAlpha = 0.0f;
	const int rotOrangeScore = -200;

	//FALL_UP_CLOCK
	int clockUpImg = 0;
	const char clockUpId = 'g';
	const int NumClockUp = 5;
	const float clockUpAdsSpeed = 5.0f;
	const float clockUpAlpha = 0.0f;

	//FALL_DOWN_CLOCK
	int clockDownImg = 0;
	const char clockDownId = 'h';
	const int NumClockDown = 5;
	const float clockDownAdsSpeed = 5.0f;
	const float clockDownAlpha = 0.0f;

	//FALL_UP_SHOES
	int shoesUpImg = 0;
	const char shoesUpId = 'i';
	const int NumShoesUp = 5;
	const float shoesUpAdsSpeed = 5.0f;
	const float shoesUpAlpha = 0.0f;

	//FALL_DOWN_SHOES
	int shoesDownImg = 0;
	const char shoesDownId = 'j';
	const int NumShoesDown = 5;
	const float shoesDownAdsSpeed = 5.0f;
	const float shoesDownAlpha = 0.0f;


	CONTAINER() {
		//�^�C�g���Ɖ�ʂ̑傫��
		initialize("�̌��΁[��", windowWidht, windowHeight,FULLSCREEN);
		//�摜���[�h-------------------------------------------------------------
		//�^�C�g���摜���[�h
		backGroundImg = loadImage("�^�C�g�����.png");
		titleImg = loadImage("�t���o�P.png");
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
		int AllNumImg = loadImage("suuzi.png");
		for (int i = 0; i < 10; i++) {
			scoreImg[i] = divideImage(AllNumImg, 75 * i, 0, 75, 75);
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

		
		//CONTAINER��n���Ƃ�----------------------------------------------------
		CHARACTER::setContainer(this);
		FALL::setContainer(this);
		FALL_MANEGER::setContainer(this);
		IMG::setContainer(this);
		TITLE_MANEGER::setContainer(this);
	}

};
