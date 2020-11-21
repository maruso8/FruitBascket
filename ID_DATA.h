#pragma once
#include<string>

//データの一つを読み込むのに必要なクラス

class ID_DATA {
	//データの名前 std::stringはなんか便利なcharとでも思っておこう
	std::string Name;
	//Idの名前　furuitのために追加
	char Id = 0;
public:
	//セッター
	void setName(const char* name);
	void setId(const char id);
	//ゲッター
	std::string name();
	char id();

};
