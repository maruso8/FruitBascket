#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"graphic.h"
#include"debugStr.h"

#include"window.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"PLAYER.h"
#include"FALL_MANEGER.h"
#include"FALL_APPLE.h"
#include"CHECK.h"
#include"IMG.h"

#include"TITLE_MANEGER.h"

#include"FADE.h"
#include"SCORE.h"
#include"TIME_LIMIT.h"

#include"sound.h"





GAME::GAME() {
	srand((unsigned int)time(NULL));
	 C = new CONTAINER;
	 Player = new PLAYER;
	 FallManeger = new FALL_MANEGER;
	 check = new CHECK;
	 Fade = new FADE;
	 TitelManeger = new TITLE_MANEGER;
	 Score = new SCORE;
	 TimeLimit = new TIME_LIMIT;

	
	 C->LoadData("data/init.txt");

	 TimeCnt = C->getIData("TimeCnt");
	 FallFruitCnt = C->getIData("fallCnt");
	 FallItemCnt = C->getIData("fallCnt");


	 PlayerScore = 5000;


	 Bgm = loadSound("タイトルBGM.wav");
	 scoreImage = loadImage("sukoa.png");
	 playLoopSound(Bgm);


}

GAME::~GAME() {
	delete C;
	delete Player;
	delete FallManeger;
	delete check;
	delete Fade;
	delete TitelManeger;
	delete Score;
	delete TimeLimit;
}

void GAME::main() {
	getInput();
	clearTarget();
	TitelManeger->backGround_Draw();

	switch (GameStart) {
	case GAME_START_TITEL:
		TitelManeger->title_Draw(GameCheck);

		if (GameTitel == GAME_PLAY) {
			check->check(&GameCheck);
			if (isTrigger(KEY_Z)) {
				if (GameCheck == 0) { GameTitel = GAME_WAIT; }
				if (GameCheck == 1) { GameTitel = GAME_HowToPlay; }
				if (GameCheck == 2) { GameTitel = GAME_CREDIT; }
				if (GameCheck == 3) { GameTitel = GAME_END; }
			}
		}


		if (GameTitel == GAME_WAIT) {
			if (Fade->alpha() >= 1) {
				TitelManeger->changeGameImg();
				stopSound(Bgm);
				Bgm = loadSound("ゲームプレイBGM.wav");
				playLoopSound(Bgm);

				flag = 0;

				GameStart = GAME_START_PLAY;



			}
			else { Fade->fadeOut(); }
		}


		if (GameTitel == GAME_HowToPlay) {
			if (TitelManeger->howToPlay()) {
				GameTitel = GAME_PLAY;
			}
		}

		if (GameTitel == GAME_CREDIT) {
			if (TitelManeger->credit()) {
				GameTitel = GAME_PLAY;
			}
		}


		FallManeger->update();

		break;



	case GAME_START_PLAY:

		if (Fade->alpha() <= 0) {
			TimeLimit->timeLimitdraw(TimeCnt);


			if (FallFruitCnt == 0) {
				Id = check->fruitIdCheck(rand() % 4);
				FallManeger->appear(Id);
				FallLotFruitCnt++;

				Id = check->fruitIdCheck(rand() % 4);
				FallManeger->appear(Id);


				FallFruitCnt = rand() % 10 + (TimeCnt / 239 + 1) + 30;


				if (FallLotFruitCnt > rand() % 2 + 1) {
					Id = check->lotFruitIdCheck(rand() % 2);
					FallManeger->appear(Id);
					FallLotFruitCnt = 0;
				}

			}
			else { FallFruitCnt--; }

			if (FallItemCnt == 0) {

				iId = check->itemIdCheck(rand() % 4);
				FallManeger->appear(iId);

				FallItemCnt = rand() % 60 + 120;
			}
			else { FallItemCnt--; }


			TimeCnt--;



			FallManeger->update();
			Player->update();

			Id = FallManeger->collision(Player->top(), Player->bottom(), Player->left(), Player->right());

			if ('a' <= Id && Id <= 'f') { PlayerScore += FallManeger->getScore(Id); }
			if (Id == 'g') { TimeCnt += 600; }
			if (Id == 'h') { TimeCnt -= 600; }
			if (Id == 'i') { Player->speedUp(); }
			if (Id == 'j') { if (Player->adsSpeed() > 5.5f) { Player->speedDown(); } }



			FallManeger->draw();
			Player->draw();





			if (TimeCnt <= 0) {
				TitelManeger->changeTitleImg();
				FallManeger->deleteAlpha();
				GameStart = GAME_START_SCORE;
			}

		}
		else {
			Fade->fadeIn();
			FallManeger->draw();
			Player->draw();
			FallFruitCnt = C->fallCnt;
			TimeCnt = C->getIData("TimeCnt");


		}


		drawImage(scoreImage, 0, 0);
		Score->scoredraw(PlayerScore);


		break;




	case GAME_START_SCORE:

		if (Fade->alpha() <= 0) {
			if (flag == 0) {
				if (GameLevel == GAME_LEVEL_EASY) { C->saveData("data/score.easy.txt", PlayerScore); }
				if (GameLevel == GAME_LEVEL_NORMAL) { C->saveData("data/score.normal.txt", PlayerScore); }
				if (GameLevel == GAME_LEVEL_HARD) { C->saveData("data/score.hard.txt", PlayerScore); }
				flag++;
			}


			if (isTrigger(KEY_Z)) {
				TitelManeger->changeTitleImg();
				FallManeger->deleteAlpha();
				GameStart = GAME_START_TITEL;
				GameTitel = GAME_PLAY;
			}
		}
		else {
			Fade->fadeIn();
		}

		break;


	}



	FallManeger->draw();
	setDebugStr("TimeCnt=%d", GameTitel);
	setDebugStr("TimeCnt=%d", GameStart);


	drawDebugStr();


	Fade->draw();





	present();

}

bool GAME::end() {
	if (GameTitel == GAME_END) {	
			return true;
	}
	return false;

}