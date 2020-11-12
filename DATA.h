#pragma once
#include<string>

//データの一つを読み込むのに必要なクラス

class DATA {
	//データ値　記載されている数字を返すための変数
	float Value = 0;
	//データの名前 std::stringはなんか便利なcharとでも思っておこう
	std::string Name;
public:
	//セッター
	void setValue(float value);
	void setName(const char* name);
	//ゲッター
	float value();
	std::string name();

};
