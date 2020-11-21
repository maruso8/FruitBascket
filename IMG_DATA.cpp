#include"IMG_DATA.h"
#include"graphic.h"



void IMG_DATA::setName(const char* name){
	Name = name;
}

void IMG_DATA::setImg(const char* name) {
	Img = loadImage(name);
}


std::string IMG_DATA::name() { return Name; }
int IMG_DATA::img() { return Img; }
