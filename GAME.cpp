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
#include"CHECK.h"
#include"IMG.h"
#include"TITLE_MANEGER.h"
#include"SCORE_RANK.h"
#include"PROCESS.h"

#include"SCORE.h"
#include"TIME_LIMIT.h"
#include"SOUND_MANEGER.h"
#include"SCORE_MANEGER.h"




GAME::GAME() {
	srand((unsigned int)time(NULL));
	C = CONTAINER::getInstance();
	C->LoadData("data/Data.txt");
	TitelManeger = TITLE_MANEGER::getInstans();
	SoundManeger = SOUND_MANEGER::getInstans();
	ScoreManeger = SCORE_MANEGER::getInstans();
	Proc = PROCESS::getInstans();

	check = new CHECK;
	TimeLimit = new TIME_LIMIT;
	SoundManeger->getTitelBgm();
}

GAME::~GAME() {
	TITLE_MANEGER::Delete();
	SCORE_MANEGER::Delete();
	SOUND_MANEGER::Delete();
	PROCESS::Delete();
	CONTAINER::Delete();

	delete check;
	delete TimeLimit;
}

void GAME::main() {
	getInput();
	clearTarget();
	TitelManeger->backGround_Draw();

	switch (GameStart) {
	case GAME_STATE_TITEL:
		TitelManeger->title_Draw(GameCheck);


		if (GameLevel == GAME_LEVEL_NULL) {
			if (Proc->FadeIn()) {
				//ここでタイトル関連の処理を行う
				if (Proc->flag()) {
					selectLevel();
					TitelManeger->Level_Draw(GameLevelCheck);
					if (isTrigger(KEY_X)) {
						SoundManeger->getDecisionSE();
						Proc->flagOff();
					}
				}
				else {
					if (GameTitle == 0) {
						check->check(GameCheck);
						if (isTrigger(KEY_Z)) {
							Title = GameCheck;
							SoundManeger->getDecisionSE();
							GameTitle = GameCheck;
							if (GameTitle == 0) { Proc->flagOn(); }
							else { GameTitle = 1; }
						}
					}
					if (GameTitle == 1) {
						if (isTrigger(KEY_X)) {
							Title = 5;
							SoundManeger->getDecisionSE();
							Proc->flagOff();
							GameTitle = 0;
						}
						//遊び方orクレジットの表示
						Proc->gameSelect(Title);
					}
				}
			}
		}
		else if (Proc->Fadeout()) {
			gameInit();
			TitelManeger->changeGameImg();
			SoundManeger->stopBgm();
			SoundManeger->getGameBgm();
			GameStart = GAME_STATE_PLAY;
		}

		break;

	case GAME_STATE_PLAY:

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
			PlayerScore += Proc->score(Id, PlayerScore,GameLevel);
			TimeCnt += Proc->item(Id);
			TimeCnt--;
			//アップデート＆描画
			ScoreManeger->scoredraw(PlayerScore);
			//制限時間通知
			if ((TimeCnt <= 600) && (TimwNotice == 0)) { TimwNotice = 1; SoundManeger->getTimwNotice(); }
			else if ((TimeCnt >= 600) && (TimwNotice == 1)) { TimwNotice = 0; }

			if (TimeCnt <= 0) {
				C->saveData(GameLevel,PlayerScore);
				SoundManeger->stopBgm();
				SoundManeger->getScoreBgm();
				ScoreManeger->scoreRankInit();
				GameStart = GAME_STATE_SCORE;
			}
		}
		break;




	case GAME_STATE_SCORE:


		Proc->scoredraw();
		//ランキングを稼働させる
		;
		if (ScoreManeger->scoreRankDraw(GameLevel, PlayerScore)) {
			if (Proc->flag()) {
				//Zキーを押すとタイトルに戻る
				if (isTrigger(KEY_Z)) {
					Proc->flagOff();
				}
			}
			else {
				if (Proc->Fadeout()) {
					titelInit();
				}
			}
		}
		if (isTrigger(KEY_Z)) { ScoreManeger->skip(); }
		break;
	}

	present();

}

bool GAME::end() {
	if (Title == 3) {
		return true;
	}
	return false;

}


int GAME::selectLevel() {

	if (isTrigger(KEY_UP)) { GameLevelCheck--; SoundManeger->getSelectSE(); }
	if (isTrigger(KEY_DOWN)) { GameLevelCheck++; SoundManeger->getSelectSE(); }
	if (GameLevelCheck > 2) { GameLevelCheck = 0; }
	if (GameLevelCheck < 0) { GameLevelCheck = 2; }

	if (isTrigger(KEY_Z)) {
		SoundManeger->getDecisionSE();
		if (GameLevelCheck == 0) { GameLevel = GAME_LEVEL_EASY; }
		if (GameLevelCheck == 1) { GameLevel = GAME_LEVEL_NORMAL; }
		if (GameLevelCheck == 2) { GameLevel = GAME_LEVEL_HARD; }
	}
	return GameLevel;
}




void GAME::gameInit() {
	TimeCnt = C->getIData("TimeCnt");
	PlayerScore = 0;
}

void GAME::titelInit() {
	SoundManeger->stopBgm();
	SoundManeger->getTitelBgm();
	TitelManeger->changeTitleImg();
	Proc->deleteAlpha();
	C->DeleteRank();
	GameStart = GAME_STATE_TITEL;
	GameTitle = 0;
	GameLevel = GAME_LEVEL_NULL;
	Title = 5;
}