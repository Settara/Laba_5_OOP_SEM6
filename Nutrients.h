#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//������� ��������� ������� �������� �� ���������
class Nutrients
{
public:
	Nutrients() {  };	//����������� ��� ��������� ������������� ��� ���������
	virtual void Mix() = 0;								//����� ��������� ��������� � �����
	//virtual void Add(Nutrients* uk) {};					//����� ��������� ����� ������ � ������� ������
	//virtual void Remove(Nutrients* uk) {};				//����� ������� ������ �� �������� �������
	//virtual Nutrients* GetChild(int node) { return nullptr; };//����� ��������� ��������� � �����

};

