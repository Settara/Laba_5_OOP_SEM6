#include "IDynamicDatabase.h"

IDynamicDatabase::IDynamicDatabase(string DinamicDatabaseName)
{
	this->DinamicDatabaseName = DinamicDatabaseName;
}

void IDynamicDatabase::SetTemperatureCurrent(ISensor* sensor)
{
	sensor->GetInformation();
	TemperatureCurrent = sensor->GiveInformation();
}

void IDynamicDatabase::SetHumidityCurrent(ISensor* sensor)
{
	sensor->GetInformation();
	HumidityCurrent = sensor->GiveInformation();
}

void IDynamicDatabase::SetLightingCurrent(ISensor* sensor)
{
	sensor->GetInformation();
	LightingCurrent = sensor->GiveInformation();
}

int IDynamicDatabase::GetTemperatureCurrent()
{
	return TemperatureCurrent;
}

int IDynamicDatabase::GetHumidityCurrent()
{
	return HumidityCurrent;
}

int IDynamicDatabase::GetLightingCurrent()
{
	return LightingCurrent;
}