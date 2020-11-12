#include"CHARACTER.h"
#include"PLAYER.h"
#include"CONTAINER.h"

PLAYER::PLAYER() {
	Img = C->playerImg;
	Px = C->playerPx;
	Py = C->playerPy;
	Widht = C->playerWidht;
	Height = C->playerHeight;
	AdsSpeed = C->playerAdsSpeed;

	Top = C->playerHitTop;
	Bottom = C->playerHitBottom;
	Left = C->playerHitLeft;
	Right = C->playerHitRight;

}

void PLAYER::update() {
	getInput();

	if (Px <= 0+Widht) { Px = 0+Widht; }
	else if (isPress(KEY_LEFT)) { Px -= AdsSpeed; }

	if (Px >= C->windowWidht - Widht) { Px = C->windowWidht - Widht; }
	else if (isPress(KEY_RIGHT)) { Px += AdsSpeed; }

	
}

