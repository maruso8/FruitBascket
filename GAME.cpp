#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"graphic.h"
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
#include"SCORE_IMG.h"
#include"PROCESS.h"

#include"SCORE.h"
#include"TIME_LIMIT.h"
#include"SOUND_MANEGER.h"





GAME::GAME() {
	srand((unsigned int)time(NULL));
	 C = new CONTAINER;
	 C->LoadData("data/Data.txt");
	 check = new CHECK;
	 TitelManeger = new TITLE_MANEGER;
	 Score = new SCORE;
	 TimeLimit = new TIME_LIMIT;
	 ScoreImg = new SCORE_IMG;
	 Proc = new PROCESS;
	 SoundManeger = new SOUND_MANEGER;
	 SoundManeger->getTitelBgm();
}

GAME::~GAME() {
	delete C;
	delete check;
	delete TitelManeger;
	delete Score;
	delete TimeLimit;
	delete ScoreImg;
	delete Proc;
	delete SoundManeger;
}

void GAME::main() {
	getInput();
	clearTarget();
	TitelManeger->backGround_Draw();



	switch (GameStart) {
	case GAME_START_TITEL:
		TitelManeger->title_Draw(GameCheck);
		if (GameTitel == GAME_PROCESS) {
			if (isTrigger(KEY_X)) {
				GameTitel = GAME_PLAY;
				Titel = 5;
				SoundManeger->getDecisionSE(); 
			}
		}




		if (GameTitel == GAME_PLAY) {
			check->check(GameCheck);
			if (isTrigger(KEY_Z)) {
				SoundManeger->getDecisionSE();
				Titel = GameCheck;
				if(Titel==0){ GameStart=GAME_START_WAIT; }
				else { GameTitel = GAME_PROCESS; }
			}
		}

		Proc->gameSelect(Titel);

		break;


	case GAME_START_WAIT:
			selectLevel();
			TitelManeger->Level_Draw(GameLevelCheck);
			if (isTrigger(KEY_X)) {
				SoundManeger->getDecisionSE();
				GameStart = GAME_START_TITEL;
			}

			if (GameLevel != GAME_LEVEL_NULL) {
				if (Proc->Fadeout()) {
					gameInit();
					TitelManeger->changeGameImg();
					SoundManeger->stopBgm();
					SoundManeger->getGameBgm();
					GameStart = GAME_START_PLAY;
				}
			}
			break;

	case GAME_START_PLAY:

		Proc->gamedraw();
		if (Proc->FadeIn()) {
			//残り時間の表示
			TimeLimit->timeLimitdraw(TimeCnt);
			//フルーツorアイテムの落下
			Proc->fallFruit(TimeCnt, PlayerScore, GameLevel);
			Proc->fallItem();
			//当たり判定
			Id = Proc->collision();
			//ここでスコアチェック
			PlayerScore += Proc->score(Id,PlayerScore);
			TimeCnt += Proc->item(Id);
			TimeCnt--;
			//アップデート＆描画
			Score->scoredraw(PlayerScore);
			//制限時間通知
			if ((TimeCnt <= 600)&& (TimwNotice == 0)) { TimwNotice = 1; SoundManeger->getTimwNotice();  }
			else if((TimeCnt >= 600) && (TimwNotice == 1)) { TimwNotice = 0; }

			if (TimeCnt <= 0) {
				Proc->seveLoad(GameLevel, PlayerScore);
				SoundManeger->stopBgm();
				SoundManeger->getScoreBgm();
				GameStart = GAME_START_SCORE;
			}
		}
		break;




	case GAME_START_SCORE:

		Proc->gamedraw();
		ScoreImg->draw();
		//ランキングを稼働させる
		ScoreImg->drawRankScore(PlayerScore);

		//Zキーを押すとタイトルに戻る
		if (isPress(KEY_Z)) {
			SoundManeger->stopBgm();
			SoundManeger->getTitelBgm();
			TitelManeger->changeTitleImg();
			Proc->deleteAlpha();
			C->DeleteRank();
			GameStart = GAME_START_TITEL;
			GameTitel = GAME_PLAY;
			GameLevel = GAME_LEVEL_NULL;
			Titel = 5;
		}

		break;

	}

	present();

}

bool GAME::end() {
	if (Titel == 3) {
		return true;
	}
	return false;

}


int GAME::selectLevel() {
	
	if (isTrigger(KEY_UP)) { GameLevelCheck--; SoundManeger->getSelectSE(); }
	if (isTrigger(KEY_DOWN)) { GameLevelCheck++; SoundManeger->getSelectSE();}
	if (GameLevelCheck > 2) { GameLevelCheck = 0; }
	if (GameLevelCheck < 0) { GameLevelCheck = 2; }
	
	if (isTrigger(KEY_Z)) {
		SoundManeger->getDecisionSE();
		if (GameLevelCheck == 0) { GameLevel = GAME_LEVEL_EASY; }
		if (GameLevelCheck == 1) { GameLevel = GAME_LEVEL_NORMAL; }
		if (GameLevelCheck == 2) { GameLevel = GAME_LEVEL_HARD; }
	}


	return GameLevelCheck;

}


void GAME::gameInit() {
	TimeCnt = C->getIData("TimeCnt");
	PlayerScore = 0;
}