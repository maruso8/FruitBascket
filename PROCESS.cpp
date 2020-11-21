#include<stdio.h>
#include<cassert>
#include"CONTAINER.h"
#include"PROCESS.h"

CONTAINER* PROCESS::C = 0;

void PROCESS::seveLoad(int Level, int score) {
	switch (Level)
	{
	case 0:
		C->saveData("data/score.easy.dat", score);
		break;
	case 1:
		C->saveData("data/score.normal.dat", score);
		break;

	case 2:
		C->saveData("data/score.hard.dat", score);
		break;

	default:
		assert();
		break;
	}

}