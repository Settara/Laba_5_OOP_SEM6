#pragma once
#include "Nutrients.h"

//����� ��������� ��������� �����
class Humus : public Nutrients
{
public:
	Humus() { NutrientsName = "Humus"; }	//��������������� ������������ 
	void Mix() override; //����� ��������� ��������� � �����
};

