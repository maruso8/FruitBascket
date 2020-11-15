#include<cassert>
#include<stdio.h>
#include"DATA.h"
#include"CONTAINER.h"



#include<string>



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

	//フルーツ画像ロード
	appleImg = loadImage("リンゴ.png");
	bananaImg = loadImage("バナナ.png");
	orangeImg = loadImage("ミカン.png");
	strawberryImg = loadImage("イチゴ.png");
	rotAppleImg = loadImage("h_ringo.png");
	rotOrangeImg = loadImage("h_mikan.png");
	clockUpImg = loadImage("t_up.png");
	clockDownImg = loadImage("t_down.png");
	shoesUpImg = loadImage("k_up.png");
	shoesDownImg = loadImage("k_down.png");

	//スコア画面ロード
	scoreFreamImg = loadImage("ランキング枠.png");
	char name[256] = { 0 };
	for (int i = 0; i < 3; i++) {
		sprintf_s(name, "%d位.png", i+1);
		rankNumImg[i] = loadImage(name);
	}

	//CONTAINERを渡すとこ----------------------------------------------------
	CHARACTER::setContainer(this);
	FALL::setContainer(this);
	FALL_MANEGER::setContainer(this);
	IMG::setContainer(this);
	TITLE_MANEGER::setContainer(this);
}



int CONTAINER::LoadData(const char* filename) {
	FILE* fp = 0;
	fopen_s(&fp, filename, "r");

	//fpが存在しないときは偽を返してここで停止して注意が出る。#include<cassert>で使えるようになる。
	assert(fp != 0);
	//detaファイルの一行目はdata数でなければいけない
	fscanf_s(fp, "%d", &NumData);

	//scanしたNumData分のDetaを確保
	Data = new DATA[NumData];

	//読み込み開始
	char name[256];
	float value;
	for (int i = 0; i < NumData; i++) {
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
	//データがいくつあるか求める。
	fopen_s(&fp, filename, "r");
	//fpが存在しないときは偽を返してここで停止して注意が出る。#include<cassert>で使えるようになる。
	assert(fp != 0);
	//detaファイルの一行目はdata数でなければいけない
	fscanf_s(fp, "%d", &NumData);
	//scanしたNumData分のDetaを確保
	Rank = new DATA[NumData];
	//読み込み開始
	char name[256];
	float value;
	for (int i = 0; i < NumData; i++) {
		//全てint値で読み込む
		fscanf_s(fp, "%s %f", name, 256, &value);
		Rank[i].setName(name);
		Rank[i].setValue(value);
	}
	fclose(fp);



	//ここからセーブ開始
	fopen_s(&fp, filename, "w");

	assert(fp != 0);

	//比較
	for (int i = 0; i < NumData; i++) {
		if (score > Rank[i].value()) {
			float work = Rank[i].value();
			Rank[i].setValue(score);
			score = work;
		}
	}
	//書き込み開始

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
