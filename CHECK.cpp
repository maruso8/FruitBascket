#include"CHECK.h"
#include"input.h"
#include"GAME.h"


void CHECK::check(int &check) {
	if (isTrigger(KEY_UP)) { check -= 1; }
	if (isTrigger(KEY_DOWN)) { check += 1; }
	if (check > 3) { check = 0; }
	if (check < 0) { check = 3; }
}


char CHECK::fruitIdCheck(int rand) {
	if (rand == 0) { return 'a'; }
	if (rand == 1) { return 'b'; }
	if (rand == 2) { return 'c'; }
	if (rand == 3) { return 'd'; }
	if (rand == 4) { return 'k'; }
	if (rand == 5) { return 'l'; }

}

char CHECK::lotFruitIdCheck(int rand) {
	if (rand == 0) { return 'e'; }
	if (rand == 1) { return 'f'; }
	if (rand == 2) { return 'm'; }
}

char  CHECK::itemIdCheck(int rand) {
	if (rand == 0) { return 'g'; }
	if (rand == 1) { return 'h'; }
	if (rand == 2) { return 'i'; }
	if (rand == 3) { return 'j'; }
}



