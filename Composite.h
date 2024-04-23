#pragma once
#include "Nutrients.h"

//������� �����������
class Composite : public Nutrients
{
private:
	vector<Nutrients*> childs;				//���� �������� �� �������� ���������� ���������� �� Nutrients
public:
	void Mix() override;					//����� ������� ��� ������ � ���������� � � ������� �������� ����� Mix
	void Add(Nutrients* uk);		//����� ��������� ������ � ���������
	void Remove(Nutrients* uk);	//����� ������� ������ �� ����������
	Nutrients* GetChild(int node);	//����� ���������� �� ������� ������

};

