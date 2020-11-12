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
	Alpha = 0.5;
}

void SELECT::draw(float px) {
	for (int i = 0; i < C->TotalSelect; i++) {
		drawImage(Img, Px, Py + (SelectHeight * i), COLOR(Rad, Green, Blue, Alpha));
		drawImage(SelectImg[i], Px, Py + (SelectHeight * i));
	}
}

