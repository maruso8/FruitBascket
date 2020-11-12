#include"framework.h"
#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"

void gmain() {

	GAME* game = new GAME;
	while (msgProc()) {
		game->main();
		if (game->end()) {
			break;
		}
	}
	delete game;
};



