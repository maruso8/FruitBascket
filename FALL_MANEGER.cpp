#include"CONTAINER.h"
#include"FALL.h"
#include"FALL_MANEGER.h"
#include"FALL_APPLE.h"
#include"FALL_BANANA.h"
#include"FALL_ORANGE.h"
#include"FALL_STRAWBERRY.h"
#include"FALL_ROT_APPLE.h"
#include"FALL_ROT_ORANGE.h"
#include"FALL_UP_CLOCK.h"
#include"FALL_DOWN_CLOCK.h"
#include"FALL_UP_SHOES.h"
#include"FALL_DOWN_SHOES.h"
#include"FALL_MANEGER.h"




CONTAINER* FALL_MANEGER::C = 0;

FALL_MANEGER::FALL_MANEGER() {
	
	Total += C->getIData("Numapple");
	Total += C->getIData("NumBanana");
	Total += C->getIData("NumOrange");
	Total += C->getIData("NumStrawberry");
	Total += C->getIData("NumRotApple");
	Total += C->getIData("NumRotOrange");
	Total += C->getIData("NumClockUp");
	Total += C->getIData("NumShoesUp");
	Total += C->getIData("NumClockDown");
	Total += C->getIData("NumShoesDown");


	AllFall = new FALL * [Total];
	int i,j = 0;
	for (i = 0; i < C->getIData("Numapple"); i++) { AllFall[j++] = new APPLE("apple"); }
	for (i = 0; i < C->getIData("NumBanana"); i++) { AllFall[j++] = new BANANA("banana"); }
	for (i = 0; i < C->getIData("NumOrange"); i++) { AllFall[j++] = new ORANGE("orange"); }
	for (i = 0; i < C->getIData("NumStrawberry"); i++) { AllFall[j++] = new STRAWBERRY("strawberry"); }
	for (i = 0; i < C->getIData("NumRotApple"); i++) { AllFall[j++] = new ROT_APPLE("rotApple"); }
	for (i = 0; i < C->getIData("NumRotOrange"); i++) { AllFall[j++] = new ROT_ORANGE("rotOrange"); }
	for (i = 0; i < C->getIData("NumClockUp"); i++) { AllFall[j++] = new CLOCK_UP("clockUp"); }
	for (i = 0; i < C->getIData("NumShoesUp"); i++) { AllFall[j++] = new SHOES_UP("shoesUp"); }
	for (i = 0; i < C->getIData("NumClockDown"); i++) { AllFall[j++] = new CLOCK_DOWN("clockDown"); }
	for (i = 0; i < C->getIData("NumShoesDown"); i++) { AllFall[j++] = new SHOES_DOWN("shoesDown"); }


}

FALL_MANEGER::~FALL_MANEGER() {
	for (int i = 0; i < Total; i++) {
		delete AllFall[i];
	}
	delete[] AllFall;
}


void FALL_MANEGER::appear(char Id) {
	for (int i = 0; i < Total; i++) {
		if(AllFall[i]->id()==Id) {
			if (AllFall[i]->alpha() <= 0) {
				AllFall[i]->appear();
				break;
			}
		}
	}
}

void FALL_MANEGER::update() {
	for (int i = 0; i < Total; i++) {
		if (AllFall[i]->alpha() > 0.0f) {
			AllFall[i]->update();
		}
	}

	

}

char  FALL_MANEGER::collision(float top, float bottom, float left, float right) {

	for (int i = 0; i < Total; i++) {
		if (AllFall[i]->alpha() <= 0.0f) {
			continue;
		}
		else {
			if (AllFall[i]->top() > 1200) {
				AllFall[i]->deleteAlpha();
			}


			if (AllFall[i]->top() < bottom &&
				top < AllFall[i]->bottom() &&
				left < AllFall[i]->right() &&
				AllFall[i]->left() < right) {
				AllFall[i]->deleteAlpha();
				return AllFall[i]->id();

			}

		}
	}
	return 0;


}


void FALL_MANEGER::draw() {
	for (int i = 0; i < Total; i++) {
		if (AllFall[i]->alpha() > 0.0f) {
			AllFall[i]->draw();
		}
	}

}

void FALL_MANEGER::deleteAlpha() {
	for (int i = 0; i < Total; i++) {
		if (AllFall[i]->alpha() > 0.0f) {
			AllFall[i]->deleteAlpha();
		}
	}
}


int FALL_MANEGER::getScore(char id){
	for (int i = 0; i < Total; i++) {
		if (AllFall[i]->id() == id) {
			return AllFall[i]->score();
		}
	}
}

