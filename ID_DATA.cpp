#include"ID_DATA.h"
#include"graphic.h"

void ID_DATA::setName(const char* name){
	Name = name;
}

void ID_DATA::setId(const char id) {
	Id = id;
}

std::string ID_DATA::name() { return Name; }
char ID_DATA::id() { return Id; }
