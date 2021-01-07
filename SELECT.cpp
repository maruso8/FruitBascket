#include"IMG.h"
#include"CONTAINER.h"
#include"SELECT.h"



SELECT::SELECT() {
	TotalSelect = C->TotalSelect;
	for (int i = 0; i < TotalSelect; i++) {
		SelectImg[i] = C->selectImg[i];
	}
	Img = C->selectFleamImg;
	Px = C->selectPx;
	Py = C->selectPy;
	Alpha = 1;
}

void SELECT::selectDraw(int select) {
	
	
	for (int i = 0; i < C->TotalSelect; i++) {
		if (select == i) {
			drawImage(Img, Px, Py + (SelectHeight * i), COLOR(Rad, Green, Blue, Alpha));

		}
		else drawImage(Img, Px, Py + (SelectHeight * i), COLOR(Rad, Green, Blue, Alpha / 2));
		drawImage(SelectImg[i], Px, Py + (SelectHeight * i));
	}
	
}

