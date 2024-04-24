#pragma once
#include "Nutrients.h"

//Класс реализует удобрение гумус
class Humus : public Nutrients
{
public:
	Humus() { }	//Переопределение конструктора 
	void Mix() override; //Метод добавляет удобрение в почву
};

