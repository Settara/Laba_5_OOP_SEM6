#pragma once
#include "Nutrients.h"

//����� ��������� ��������� ����
class Peat : public Nutrients
{
public:
	Peat() { }	//��������������� ������������ 
	void Mix() override; //����� ��������� ��������� � �����
};

