#pragma once
#include "Characteristic.h"
#include "ISensor.h"

//����� ������������ ���� ������
class IDynamicDatabase
{
private:
	string DinamicDatabaseName;	 //���� ������ ��� ���� ������
	int TemperatureCurrent;		 //���� ������ ������� �������� �����������
	int HumidityCurrent;		 //���� ������ ������� �������� ��������� 
	int LightingCurrent;		 //���� ������ ������� �������� ��������� 

public:
	IDynamicDatabase(string DynamicDatabaseName);//���������� ������������� ��� ���� ������
	void SetTemperatureCurrent(ISensor* sensor); //����� ���������� ������ � ������������� �������� ���� TemperatureCurrent
	void SetHumidityCurrent(ISensor* sensor);	 //����� ���������� ������ � ������������� �������� ���� HumidityCurrent
	void SetLightingCurrent(ISensor* sensor);	 //����� ���������� ������ � ������������� �������� ���� LightingCurrent
	int GetTemperatureCurrent();				 //����� ���������� �������� ���� TemperatureCurrent
	int GetHumidityCurrent();					 //����� ���������� �������� ���� HumidityCurrent
	int GetLightingCurrent();					 //����� ���������� �������� ���� LightingCurrent

};