#pragma once
#include "Nutrients.h"

//����� ��������� ��������� �����
class Humus : public Nutrients
{
public:
	Humus() { }	//��������������� ������������ 
	void Mix() override; //����� ��������� ��������� � �����
};

