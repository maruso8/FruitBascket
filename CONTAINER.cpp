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




CONTAINER::CONTAINER() {
	//タイトルと画面の大きさ
	initialize("体験ばーん", windowWidht, windowHeight, FULLSCREEN);
	//画像ロード-------------------------------------------------------------
	//タイトル画像ロード
	backGroundImg = loadImage("タイトル画面.png");
	titleImg = loadImage("タイトル.png");
	for (int i = 0; i < TotalSelect; i++) {
		sprintf_s(selectName, "%s_%d.png", "aka", i);
		selectImg[i] = loadImage(selectName);
	}
	selectFleamImg = loadImage("タイトルうふふ.png");
	howToPlayImg = loadImage("play.png");
	creditImg = loadImage("S.jpg");
	signalImg = loadImage("矢印.png");

	fadeinImg = loadImage("フェードイン.png");
	freamImg = loadImage("遊び方の枠背景.png");

	//ゲームメイン画像ロード
	gameBackGroundImg = loadImage("ゲーム背景.png");
	playerImg = loadImage("プレイヤー.png");

	//スコア画像ロード
	scoreImg = loadImage("sukoa.png");
	int AllNumImg = loadImage("suuzi.png");
	for (int i = 0; i < 10; i++) {
		scoreNumImg[i] = divideImage(AllNumImg, 75 * i, 0, 75, 75);
	}

	
	bgm = loadSound("タイトルBGM.wav");


	//スコア画面ロード
	scoreFreamImg = loadImage("ランキング枠.png");
	char name[256] = { 0 };
	for (int i = 0; i < 3; i++) {
		sprintf_s(name, "%d位枠.png", i+1);
		rankNumImg[i] = loadImage(name);
	}

	//CONTAINERを渡すとこ----------------------------------------------------
	CHARACTER::setContainer(this);
	FALL::setContainer(this);
	FALL_MANEGER::setContainer(this);
	IMG::setContainer(this);
	TITLE_MANEGER::setContainer(this);
	PROCESS::setContainer(this);
	
}



int CONTAINER::LoadData(const char* filename) {
	FILE* fp = 0;
	fopen_s(&fp,filename, "r");

	//fpが存在しないときは偽を返してここで停止して注意が出る。#include<cassert>で使えるようになる。
	assert(fp != 0);
	//Dataファイルの最初はImg、Id、Dataの数でなければならない
	for (int i = 0; i < 3; i++) {
		fscanf_s(fp, "%d", &DataNum[i]);
	}
	//scanしたNumData分のDetaをそれぞれ確保
	ImgData = new IMG_DATA[DataNum[0]];
	IdData = new ID_DATA[DataNum[1]];
	Data = new DATA[DataNum[2]];
	


	//読み込み開始-----------------------------------------------------------------------------------------------
	//画像の読み込み
	char name[256];
	int Img = 0;
	for (int i = 0; i < DataNum[0]; i++) {
		fscanf_s(fp, "%s %d", name, 256, &Img);
		ImgData[i].setName(name);
		ImgData[i].setImg(name);
	}

	//Idの読み込み
	char Id;
	for (int i = 0; i < DataNum[1]; i++) {
		fscanf_s(fp, "%s %c", name, 256, &Id);
		IdData[i].setName(name);
		IdData[i].setId(Id);
	}

	float value;
	for (int i = 0; i < DataNum[2]; i++) {
		//全てfloat値で読み込む。文字列をもらう場合は文字列の最大数を指定する。超えたら受け取らない(スキップする)
		//fscan_fは対象の使用回数＝段落となっている。つまりscanfすると一列全てscanfする。
		fscanf_s(fp, "%s %f", name, 256, &value);
		Data[i].setName(name);
		Data[i].setValue(value);
	}

	fclose(fp);

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

int CONTAINER::saveData(const char* filename, int score) {

	FILE* fp;
	rank = new RANK[TotalRankNum];



	fopen_s(&fp, filename, "rb");
	//fpが存在しないときは偽を返してここで停止して注意が出る。#include<cassert>で使えるようになる。
	assert(fp != NULL);

	//個々の修正をする！
	//SEをやる

	for (int i = 0; i < 3; i++) {
		fread(&rank[i].Rank, sizeof(char), 5, fp);
		fread(&rank[i].RankScore, sizeof(int), 1, fp);
	}

	fclose(fp);



	//ここからセーブ開始
	fopen_s(&fp, filename, "wb");
	assert(fp == NULL);

	//比較
	for (int i = 0; i < 3; i++) {
		if (score > rank[i].RankScore) {
			float work = rank[i].RankScore;
			rank[i].RankScore = score;
			score = work;
		}
	}

	//書き込み開始
	for (int i = 0; i < 3; i++) {
		fwrite(&rank[i].Rank, sizeof(char), 5, fp);
		fwrite(&rank[i].RankScore, sizeof(int), 1, fp);
	};

	fclose(fp);

	return 0;
}

void CONTAINER::DeleteRank() {
	if (rank) {
		//new data*[num]のようにnewを*(ポインタ)で作ってないのでdelete[]でOK。 
		delete[] rank;
		rank = 0;
	}
}