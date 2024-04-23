#pragma once
#include "Nutrients.h"

//Класс реализует удобрение торф
class Peat : public Nutrients
{
public:
	Peat() { NutrientsName = "Peat"; }	//Переопределение конструктора 
	void Mix() override; //Метод добавляет удобрение в почву
};

