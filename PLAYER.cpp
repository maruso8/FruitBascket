#include"CHARACTER.h"
#include"PLAYER.h"
#include"CONTAINER.h"

PLAYER::PLAYER() {
	MoveImg = C->playerImg;
	Img = C->playerImg;
	RImg = C->playerRImg;
	LImg = C->playerLImg;
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
	
	MoveImg = Img;
	if (isPress(KEY_LEFT)) {
		MoveImg = LImg;
		if (Px <= 0 + Widht) { Px = 0 + Widht; }
		else { Px -= AdsSpeed; }
	}

	if (isPress(KEY_RIGHT)) {
		MoveImg = RImg;
		if (Px >= C->windowWidht - Widht) { Px = C->windowWidht - Widht; }
		else { Px += AdsSpeed; }
	}
}

void PLAYER::stenRecovery() {
	AdsSpeed = C->playerAdsSpeed;
};


