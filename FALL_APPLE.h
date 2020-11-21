#pragma once
#include"FALL.h"

class APPLE:public FALL {
public:
	//基底クラスのコンストラクタを宣言
	using FALL::FALL;
};