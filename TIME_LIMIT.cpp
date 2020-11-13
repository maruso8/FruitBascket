#include"IMG.h"
#include"CONTAINER.h"
#include"TiME_LIMIT.h"

#include"graphic.h"
#include"debugStr.h"

TIME_LIMIT::TIME_LIMIT() {
	for (int i = 0; i < 10; i++) {
		TimeImg[i] = C->scoreNumImg[i];
	}
	Px = C->timePx;
	Py = C->timePy;
}

void TIME_LIMIT::timeLimitdraw(int Time){

	int place = 10;
	int fleam = 60;
	int num = 0;
	int sec = 0;
	int min = 0;

	sec = Time / fleam;
	min = sec / fleam;

	drawImage(TimeImg[min], 0, 75);

	for (int i = 0; i < 2; i++) {
		if (sec % fleam != 0) {
			sec %= fleam;
			num = sec / place;
			sec %= place;
			drawImage(TimeImg[num], 75 * i + 75, 75);
			place /= 10;

		}
		else {drawImage(TimeImg[0], 75 * i + 75, 75);}
	}

}
