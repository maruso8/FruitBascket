#include"DATA.h"

void DATA::setValue(float value){
	Value = value;
}

void DATA::setName(const char* name){
	Name = name;
}

float DATA::value() { return  Value; }
std::string DATA::name() { return Name; }