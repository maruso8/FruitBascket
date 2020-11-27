#pragma once
#include<stdio.h>
#include"graphic.h"
#include"framework.h"
#include"CHARACTER.h"
#include"FALL.h"
#include"FALL_MANEGER.h"
#include"IMG.h"
#include"TITLE_MANEGER.h"


#include<string>



//DATAの値を入れるところ。

class CONTAINER {
	
	class DATA* Data = 0;
	class ID_DATA*IdData = 0;
	class IMG_DATA* ImgData = 0;

	int DataNum[3] = { 0 };

	int TotalRankNum = 3;
	


public:
	CONTAINER();
	~CONTAINER();
	//ファイルからデータを読み込む
	int LoadData(const char* filename);
	//データをint値で取得
	int getIData(const char* name);
	//データをfloat値で取得
	float getFData(const char* name);
	//データをchar値で取得
	char getCData(const char* name);
	//ファイルにデータを書き込む
	int saveData(const char* filename, int score);
	//ランクを消して容量確保
	void DeleteRank();

	int bgm = 0;
	//CONTAINER内外で使うデータ-------------------------------------------------
	class RANK {
	public:
		char Rank[5] = {};
		int RankScore = 0;
	};


	RANK* rank = 0;

	//ここからCONTAINER外のデータ------------------------------------------------

	//SYSTEM 
	const int windowWidht = 1920;//1920
	const int windowHeight = 1080;//1080
	const int fallCnt = 100;
	int fadeinImg = 0;
	float fadePx = 0.0f;
	float fadePy = 0.0f;
	COLOR fadeColor = COLOR(1, 1, 1, 0);
	float fadeDecayAlpha = 1.0f / 50.0f;
	//タイトル関連----------------------------------------------------------------
	//BACK_GROUND 
	int backGroundImg = 0;
	int gameBackGroundImg = 0;
	const float backGroundPx = 0.0f;
	const float backGroundPy = 0.0f;
	const int backGroundNum = 1;

	//TITLE
	int titleImg = 0;
	const float titlePx = 1120.0f;
	const float titlePy = 0.0f;
	const int titleNum = 1;

	//SELECT 
	int selectImg[4] = { };
	int selectLevelImg[3] = { };
	int selectFleamImg = 0;
	char selectName[256];
	const int TotalSelect = 4;
	const float selectPx = 50.0f;
	const float selectPy = 400.0f;
	const float selectHeight = 175.0f;
	const COLOR selectColor = COLOR(1.0f, 1.0f, 1.0f, 0.5f);
	const int selectNum = 4;

	const float LevelPx = 650;
	const float LevelPy = 300;

	const float LevelSelectPx = 1250;
	const float LevelSelectPy = 325;
	const float LevelSelectHeight = 200;


	// FREAM 
	int freamImg = 0;
	const float freamPx = 500.0f;
	const float freamPy = 50.0f;
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

	//ゲームプレイ関連---------------------------------------------------
	//GAME_PLAY
	int scoreImg = 0;
	int scoreNumImg[10] = { 0 };
	const int NumOfNum = 10;
	const float scorePx = 225.0f;
	const float scorePy = 0.0f;
	const float timePx = 0.0f;
	const float timePy = 75.0f;

	//FALL_FRUIT&ITEM
	const float fallRadius = 50.0f;//75

	//PLAYER
	int playerImg = 0;
	int playerRImg = 0;
	int playerLImg = 0;
	const float playerPx = 500.0f;
	const float playerPy = 930.0f;
	const float playerAdsSpeed = 10.0f;
	const float playerWidht = 70.0f;
	const float playerHeight = 111.0f;

	const float playerHitTop = 0.0f;//15
	const float playerHitBottom = 10.0f;//27
	const float playerHitLeft = 50.0f;//78
	const float playerHitRight = 50.0f;//74

	//スコア関連-------------------------------------------------------
	//SCORE
	int scoreFreamImg = 0;
	int rankNumImg[3] = { 0 };
	const int rankNum = 3;
	const float rankPx = 900.0f;
	const float rankPy = 200.0f;
	const float rankWidth = 75.0f;
	const float scoreImgPx = 600.0f;
	const float scoreImgPy = 200.0f;
	const float scoreSpace = 200.0f;
	const float PlayerScorePx = 750.0f;
	const float PlayerScorePy = 850.0f;



};

