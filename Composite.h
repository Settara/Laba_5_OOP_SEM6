#pragma once
#include "Nutrients.h"

//Паттерн Компоновщик
class Composite : public Nutrients
{
private:
	vector<Nutrients*> childs;				//Поле отвечает за хранение контейнера указателей на Nutrients
public:
	void Mix() override;					//Метод обходит все листья в контейнере и у каждого вызывает метод Mix
	void Add(Nutrients* uk);		//Метод добавляет объект в контейнер
	void Remove(Nutrients* uk);	//Метод удаляет объект из контейнера
	Nutrients* GetChild(int node);	//Метод вовзращает по индексу объект

};

