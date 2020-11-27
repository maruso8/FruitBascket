#pragma once
#include"input.h"
#include"CHARACTER.h"
#include"CONTAINER.h"
#include"debugStr.h"
#include"window.h"



class PLAYER:public CHARACTER {
public:
	PLAYER();
	
	void update();
	void stenRecovery();

private:

};