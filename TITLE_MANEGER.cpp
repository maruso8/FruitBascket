#include"TITLE_MANEGER.h"
#include"CONTAINER.h"
#include"IMG.h"
#include"TITLE.h"
#include"SELECT.h"
#include"SIGNAL.h"
#include"BACK_GROUND.h"
#include"SOUND_MANEGER.h"
#include"input.h"


CONTAINER* TITLE_MANEGER::C = 0;

TITLE_MANEGER::TITLE_MANEGER() {
	C = CONTAINER::getInstance();
	SoundManeger = new SOUND_MANEGER;
	BackGround = new BACK_GROUND;
	Title = new TITLE;
	Select = new SELECT;
	Signal = new SIGNAL;

	Px = C->HowToCreditPx;
	Py = C->HowToCreditPy;

}

TITLE_MANEGER::~TITLE_MANEGER() {
	delete SoundManeger;
	delete BackGround;
	delete Title;
	delete Select;
	delete Signal;
}

void TITLE_MANEGER::backGround_Draw() {BackGround->draw();}

void TITLE_MANEGER::title_Draw(int gameCheck) {
	Title->draw();
	Select->selectDraw(gameCheck);
	//タイトル演出用
	if (Time == 60) {
		for (int i = 0; i < 4; i++) {
			if (gameCheck == i) {
				if (gameCheck != SE) {
					SE = gameCheck;
					SoundManeger->getSelectSE();
				}
				Signal->draw(i * Select->selectHeight());
			}
		}


	}
	else { Time++; }
}

void TITLE_MANEGER::Level_Draw(int LevelCheck) {
	Signal->Leveldraw(LevelCheck,LevelCheck);
}


void TITLE_MANEGER::changeTitleImg() { BackGround->changeTitleImg(); }

void TITLE_MANEGER::changeGameImg() { BackGround->changeGameImg(); }

bool TITLE_MANEGER::howToPlay() {
	Img = C->HowToPlayImg[HowToPage];
	drawImage(Img, Px, Py);
	if (isTrigger(KEY_LEFT)) {
		HowToPage--;
		SoundManeger->getSelectSE();
		if (HowToPage < 0) { HowToPage = 0; }
	}
	if (isTrigger(KEY_RIGHT)) {
		HowToPage++;
		SoundManeger->getSelectSE();
		if (HowToPage > 2) { HowToPage = 2; }
	}

	if (isTrigger(KEY_X)) { HowToPage = 0; return true; }
	else return false;
}

bool TITLE_MANEGER::credit() {
	Img = C->CreditImg;
	drawImage(Img, Px, Py);

	if (isTrigger(KEY_X)) { return true; }
	else return false;
}
