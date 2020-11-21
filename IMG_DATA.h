#pragma once
#include<string>

//データの一つを読み込むのに必要なクラス

class IMG_DATA {
	
	//データの名前 std::stringはなんか便利なcharとでも思っておこう
	std::string Name;
	//画像番号　imgのために追加
	int Img = 0;
public:
	//セッター
	void setName(const char* name);
	void setImg(const char* name);
	//ゲッター
	std::string name();
	int img();

};
