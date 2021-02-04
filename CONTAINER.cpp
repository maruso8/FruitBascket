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

	//タイトルと画面の大きさ
	initialize("FuruitBascket", windowWidht,windowHeight, FULLSCREEN);
	//画像ロード-------------------------------------------------------------
	//タイトル画像ロード

	//loadImageFromResは先生が作ったものです。

	backGroundImg = loadImageFromRes("TitelBack");
	titleImg = loadImageFromRes("Titel");
	for (int i = 0; i < TotalSelect; i++) {
		sprintf_s(selectName, "%s_%d", "Select", i);
		selectImg[i] = loadImageFromRes(selectName);
	}
	for (int i = 0; i < 3; i++) {
		sprintf_s(selectName, "%s_%d", "Lv", i);
		selectLevelImg[i] = loadImageFromRes(selectName);
	}
	selectFleamImg = loadImageFromRes("SelectBack");
	levelSelectFleamImg = loadImageFromRes("LevelBack");
	signalImg = loadImageFromRes("Arrow");

	for (int i = 0; i < TotalHowTo; i++) {
		sprintf_s(selectName, "%s_%d", "HowTo", i);
		HowToPlayImg[i] = loadImageFromRes(selectName);
	}
	CreditImg = loadImageFromRes("Credit");


	fadeinImg = loadImageFromRes("Fade");
	freamImg = loadImageFromRes("HowToBack");

	//ゲームメイン画像ロード
	gameBackGroundImg = loadImageFromRes("GameBack");
	playerImg = loadImageFromRes("Player");
	playerRImg = loadImageFromRes("PlayerL");
	playerLImg = loadImageFromRes("PlayerR");


	//スコア画像ロード
	scoreImg = loadImageFromRes("Score");
	int AllNumImg = loadImageFromRes("Number");
	for (int i = 0; i < 10; i++) {
		scoreNumImg[i] = divideImage(AllNumImg, 75 * i, 0, 75, 75);
	}

	//スコア画面ロード
	scoreFreamImg = loadImageFromRes("ScoreBack");
	for (int i = 0; i < 3; i++) {
		sprintf_s(selectName, "No.%d", i);
		rankNumImg[i] = loadImageFromRes(selectName);
	}

	rank = new RANK[TotalRankNum];



}

CONTAINER* CONTAINER::getInstance() {
	if (!C) {//C(CONTAINER)が存在しないとき
		//コンテナを作る
		C = new CONTAINER;
	}

	//CONTAINERを渡す
	return C;
}

CONTAINER* CONTAINER::Delete() {
	if (C) {//CONTAINERが存在する時
		//deleteして0クリア
		delete C;
		C = 0;
	}

	return C;
}



int CONTAINER::LoadData(const char* filename) {


	FILE* fp = 0;	
	
	
	fopen_s(&fp, "data/Data.bin", "rb");

	//fpが存在しないときは偽を返してここで停止して注意が出る。#include<cassert>で使えるようになる。
	assert(fp != 0);

	//datにあるデータをFallDataに入れる
	fread(&FallData, sizeof(FALL_DATA), 1, fp);
	fclose(fp);



	//scanしたNumData分のDetaをそれぞれ確保
	ImgData = new IMG_DATA[FallData.NumImgData];
	IdData = new ID_DATA[FallData.NumIdData];
	Data = new DATA[FallData.NumData];

	//読み込み開始-----------------------------------------------------------------------------------------------
	//画像の読み込み
	for (int i = 0; i < FallData.NumImgData; i++) {
		ImgData[i].setName(FallData.ImgName[i].c_str());
		ImgData[i].setImg(FallData.ImgName[i].c_str());
	}

	//Idの読み込み
	for (int i = 0; i < FallData.NumIdData; i++) {
		IdData[i].setName(FallData.IdName[i].c_str());
		IdData[i].setId(FallData.Id[i]);
	}

	//Dataの読み込み
	for (int i = 0; i < FallData.NumData; i++) {

		Data[i].setName(FallData.FallDataName[i].c_str());
		Data[i].setValue(FallData.FallData[i]);
	}


	return 0;
}

CONTAINER::~CONTAINER() {
	if (Data) {
		//new data*[num]のようにnewを*(ポインタ)で作ってないのでdelete[]でOK。 
		delete[] Data;
		Data = 0;
	}
	if (IdData) {
		//new data*[num]のようにnewを*(ポインタ)で作ってないのでdelete[]でOK。 
		delete[] IdData;
		IdData = 0;
	}
	if (ImgData) {
		//new data*[num]のようにnewを*(ポインタ)で作ってないのでdelete[]でOK。 
		delete[] ImgData;
		ImgData = 0;
	}
	if (rank) {
		//new data*[num]のようにnewを*(ポインタ)で作ってないのでdelete[]でOK。 
		delete[] rank;
		rank = 0;
	}


}

int CONTAINER::getIData(const char* name) {

	int i = 0;
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
	fp = fopen ("data/score.bin", "rb");
	//fpが存在しないときは偽を返してここで停止して注意が出る。#include<cassert>で使えるようになる。
	assert(fp != NULL);
	fread(&rank[0], sizeof(RANK) * 3, 1, fp);

	fclose(fp);

	assert(rank[0].RankScore != 0);

	//ここからセーブ開始
	fopen_s(&fp, "data/score.bin", "wb");
	assert(fp != NULL);

	//比較
	for (int i = 0; i < 3; i++) {
		if (score > rank[Level].RankScore[i]) {
			float work = rank[Level].RankScore[i];
			rank[Level].RankScore[i] = score;
			score = work;
		}
	}

	//書き込み開始
	fwrite(&rank[0], sizeof(RANK)*3 , 1, fp);
	fclose(fp);

	return 0;

}
