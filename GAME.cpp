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

#include"new.h"


GAME::GAME() {
	srand((unsigned int)time(NULL));


	C = CONTAINER::getInstance();
	C->LoadData("data/Data.dat");
	TitelManeger = new TITLE_MANEGER;
	Proc = new PROCESS;
	SoundManeger = new SOUND_MANEGER;
	ScoreManeger = new SCORE_MANEGER();
	check = new CHECK;
	TimeLimit = new TIME_LIMIT;

	SoundManeger->getTitelBgm();

	TitleScene = C->TitleScene;
	TimeCntNotice = C->timeCntNotice;
}

GAME::~GAME() {
	CONTAINER::Delete();
	delete TitelManeger;
	delete Proc;
	delete SoundManeger;
	delete ScoreManeger;
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
		//���o�p��if
		if (DirectionTime >= 60) {
			if (GameLevel == GAME_LEVEL_NULL) {
				if (Proc->FadeIn()) {
					//�����Ń^�C�g���֘A�̏������s��
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
								TitleScene = GameCheck;
								SoundManeger->getDecisionSE();
								GameTitle = GameCheck;
								if (GameTitle == 0) { Proc->flagOn(); }
								else { GameTitle = 1; }
							}
						}
						if (GameTitle == 1) {
							if (isTrigger(KEY_X)) {
								TitleScene = C->TitleScene;
								SoundManeger->getDecisionSE();
								Proc->flagOff();
								GameTitle = 0;
							}
							//�V�ѕ�or�N���W�b�g�̕\��
							Proc->gameSelect(TitleScene);
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
		}
		else DirectionTime++;

		break;

	case GAME_STATE_PLAY:

		Proc->gamedraw();
		if (Proc->FadeIn()) {
			//�c�莞�Ԃ̕\��
			TimeLimit->timeLimitdraw(TimeCnt);
			//�t���[�cor�A�C�e���̗���
			Proc->fallFruit(TimeCnt, PlayerScore, GameLevel);
			Proc->fallItem();
			//�����蔻��
			Id = Proc->collision();
			//�����ŃX�R�A�`�F�b�N
			PlayerScore += Proc->score(Id, PlayerScore, GameLevel);
			TimeCnt += Proc->item(Id);
			TimeCnt--;
			//�A�b�v�f�[�g���`��
			ScoreManeger->scoredraw(PlayerScore);
			//�������Ԓʒm
			if ((TimeCnt <= TimeCntNotice) && (TimwNotice == 0)) { TimwNotice = 1; SoundManeger->getTimwNotice(); }
			else if ((TimeCnt >= TimeCntNotice) && (TimwNotice == 1)) { TimwNotice = 0; }

			if (TimeCnt <= 0) {
				SoundManeger->stopBgm();
				SoundManeger->getScoreBgm();
				ScoreManeger->scoreRankInit(GameLevel, PlayerScore);
				GameStart = GAME_STATE_SCORE;
			}
		}
		break;




	case GAME_STATE_SCORE:


		Proc->scoredraw();
		//�����L���O���ғ�������
		if (Proc->translucentOut()) {
			if (ScoreManeger->scoreRankDraw(GameLevel, PlayerScore)) {
				if (Proc->flag()) {
					//Z�L�[�������ƃ^�C�g���ɖ߂�
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
		}

		break;
	}

	present();

}

bool GAME::end() {
	if (TitleScene == 3) {
		int i = 0;
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
	
	int i = 0;
	
	PlayerScore = 0;
	TimeCnt = C->getFData("TimeCnt");

}

void GAME::titelInit() {
	SoundManeger->stopBgm();
	SoundManeger->getTitelBgm();
	TitelManeger->changeTitleImg();
	Proc->deleteAlpha();
	GameStart = GAME_STATE_TITEL;
	GameTitle = 0;
	GameLevel = GAME_LEVEL_NULL;
	TitleScene = C->TitleScene;
}