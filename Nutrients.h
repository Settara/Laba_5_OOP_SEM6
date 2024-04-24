#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Базовый интерфейс который отвечает за удобрения
class Nutrients
{
public:
	Nutrients() {  };	//Конструктор без параметра устанавливает имя удобрения
	virtual void Mix() = 0;								//Метод добавляет удобрение в почву
	//virtual void Add(Nutrients* uk) {};					//Метод добавляет новый объект в сложный объект
	//virtual void Remove(Nutrients* uk) {};				//Метод удаляет объект из сложного объекта
	//virtual Nutrients* GetChild(int node) { return nullptr; };//Метод добавляет удобрение в почву

};

