#pragma once
#include "Nutrients.h"

//����� ��������� ��������� ����
class Peat : public Nutrients
{
public:
	Peat() { NutrientsName = "Peat"; }	//��������������� ������������ 
	void Mix() override; //����� ��������� ��������� � �����
};

