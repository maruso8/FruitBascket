#include<stdio.h>
#include<cassert>

#include"sound.h"

#include"CONTAINER.h"
#include"FALL_MANEGER.h"
#include"PLAYER.h"
#include"CHECK.h"
#include"FADE.h"
#include"PROCESS.h"
#include"SOUND_MANEGER.h"


CONTAINER* PROCESS::C=0;

PROCESS::PROCESS() {
	C = CONTAINER::getInstance();
	TitelManeger = new TITLE_MANEGER;
	SoundManeger = new SOUND_MANEGER;
	FallManeger = new FALL_MANEGER;
	Player = new PLAYER;
	check = new CHECK;
	Fade = new FADE;
}


PROCESS::~PROCESS() {
	CONTAINER::Delete();
	delete TitelManeger;
	delete SoundManeger;
	delete Player;
	delete check;
	delete Fade;
	delete FallManeger;
}


void PROCESS::ProcInit() {
	FallFruitCnt = C->getIData("fallCnt");
	FallItemCnt = C->getIData("fallCnt");
}

void PROCESS::gameSelect(int GameTitel) {
	switch (GameTitel) {
	case 0:

		break;
	case 1:
		TitelManeger->howToPlay();
		break;

	case 2:
		TitelManeger->credit();
		break;

	default:
		break;
	}
}


int PROCESS::score(char Id, int score,int Level) {
	if ('a' <= Id && Id <= 'f' || 'k' <= Id && Id <= 'm') {
		if ('a' <= Id && Id <= 'd'|| 'k' <= Id && Id <= 'l') {
			SoundManeger->getFruitGetSE();
		}
		else { SoundManeger->getRotFruitGetSE(); }


		if (Level == 0) { LevelTimes = C->easyTimes; }
		if (Level == 1) { LevelTimes = C->normalTimes; }
		if (Level == 2) { LevelTimes = C->hardTimes; }

		if (Id == 'm') {return -score / 2;}
		if ('a' <= Id && Id <= 'd' || 'k' <= Id && Id <= 'l') {
			return FallManeger->getScore(Id) * LevelTimes;
		}
		return FallManeger->getScore(Id);
	}
	return 0;
	
}

int PROCESS::item(char Id) {
	if (Id == 'g') { SoundManeger->getTimeUpSE(); return 180; TimeUpCnt++; }
	if (Id == 'h') { SoundManeger->getTimeDownSE(); return -180; }
	if (Id == 'i') { SoundManeger->getShoesGetSE(); Player->speedUp(); return 0; }
	if (Id == 'j') { SoundManeger->getShoesGetSE(); if (Player->adsSpeed() > 5.5f) { Player->speedDown(); }; return 0; }
	if (Id == 'n') { SoundManeger->getRotFruitGetSE(); { Player->sten(); }  }
	return 0;
}

void  PROCESS::fallFruit(int time, int score, int Level) {
	
	if (FallFruitCnt <= 0) {
		//難易度による落下するフルーツの変更(0=easy　1=normal　2=hard)
		if (Level == 0) {
			for (int i = 0; i < 2; i++) {
				Id = check->fruitIdCheck(rand() % 5);
				FallManeger->appear(Id);
			}
		}
		if (Level == 1) {
			Id = check->fruitIdCheck(rand() % 5);
			FallManeger->appear(Id);
			Id = check->fruitIdCheck(rand() % 6);
			FallManeger->appear(Id);
		}

		if (Level == 2) {
			Id = check->fruitIdCheck(rand() % 5);
			FallManeger->appear(Id);
			Id = check->fruitIdCheck(rand() % 6);
			FallManeger->appear(Id);
		}

		FallFruitCnt = rand() % 10 + (time / 239 + 1) + 30;
		FallLotFruitCnt++;

		if (FallLotFruitCnt >rand() % 2 + 1 && Level != 0) {
			if (score >= 5000 && Level == 2) { Id = check->lotFruitIdCheck(rand() % 3); }
			else { Id = check->lotFruitIdCheck(rand() % 2); }
			FallManeger->appear(Id);
			FallLotFruitCnt = 0;
		}

	}
	else { FallFruitCnt--; }

}

void PROCESS::fallItem() {
	if (FallItemCnt == 0) {

		Id = check->itemIdCheck(rand() % 4);
		if (TimeUpCnt >= 5) {
			while (Id == 'g') {
				Id = check->itemIdCheck(rand() % 4);
			}
		}
		if (Id == 'g') { TimeUpCnt++; }

		FallManeger->appear(Id);
		FallItemCnt = rand() % 60 + 120;
	}
	else { FallItemCnt--; }
}


char PROCESS::collision() {
	Id = FallManeger->collision(Player->top(), Player->bottom(), Player->left(), Player->right());
	return Id;
}

void PROCESS::gamedraw() {
	Player->update();
	FallManeger->update();
	Player->draw();
	FallManeger->draw();
}

void PROCESS::scoredraw() {
	FallManeger->update();
	Player->draw();
	FallManeger->draw();
}

void PROCESS::deleteAlpha() {
	FallManeger->deleteAlpha();
}

bool PROCESS::FadeIn() {
	Fade->draw();

	if (Fade->alpha() <= 0) {
		return true;
	}
	else {
		Fade->fadeIn();
		return false;
	}


}

bool PROCESS::Fadeout() {
	Fade->draw();

	if (Fade->alpha() >= 1) {
		return true;
	}
	else {
		Fade->fadeOut();
		return false;
	}
}
bool PROCESS::translucentIn() {
	Fade->draw();

	if (Fade->alpha() <= 0) {
		return true;
	}
	else {
		Fade->translucentIn();
		return false;
	}

}
bool PROCESS::translucentOut() {
	Fade->draw();

	if (Fade->alpha() >= 0.5f) {
		return true;
	}
	else {
		Fade->translucentOut();
		return false;
	}
}


void PROCESS::flagOn() { Flag = 1; }
void PROCESS::flagOff() { Flag = 0; }
bool PROCESS::flag() {
	if (Flag == 1) { return true; }
	else { return false; }
};
