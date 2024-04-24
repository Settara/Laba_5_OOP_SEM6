#include "IGMS.h"

void IGMS::Management(IDynamicDatabase* DinBase, ProxyDatabase* Database, ISensor* Sensors[NSensors], IAO* Objects[NObjects], IIS* Systems[NSystem], Decorator* Decorators[NDecorators])
{
	//Создадим счетчик для компановщика 
	int compositeCounter = 3;
	//Создаем компоновщик и его листья
	Composite root;
	//Создаем массив указателей где будут храниться его листья
	Nutrients* nutrients[NNutrients];
	nutrients[0] = new Humus();
	nutrients[1] = new Humus();
	nutrients[2] = new Peat();
	//Создаем второй сложный компоновщик
	Composite embededComposition;
	nutrients[3] = new Humus();
	nutrients[4] = new Peat();
	//Добавляем адреса anower объектов
	embededComposition.Add(nutrients[3]);
	embededComposition.Add(nutrients[4]);
	//Добавляем объекты в root
	root.Add(nutrients[0]);
	root.Add(&embededComposition);
	root.Add(nutrients[1]);
	root.Add(nutrients[2]);

	//Создаем односвязный связный список 
	Node *node1, *node2, *node3;
	node1 = new Node();
	node2 = new Node();
	node3 = new Node();
	//Заполняем список
	node1->item = 1;
	node2->item = 2;
	node3->item = 3;
	node1->p_next = node2;
	node2->p_next = node3;
	//Создаем итератор
	Iterator* iterator = new Iterator(node1);
	//Узнаем что же за число там лежит
	cout << endl << "Что лежит в Node: " << iterator->operator*() << " ";
	//Передвинем итератор
	iterator->operator++();
	//Узнаем что же за число там лежит
	cout << endl << "Что лежит в Node: " << iterator->operator*() << " ";
	

	//Для начала нужно опросить все датчики чтобы узнать текущие параметры 
	do
	{
		for (int i = 0; i < NSensors; i++) {
			if (Sensors[i]->GiveName() == "TemperatureSensor")
			{
				DinBase->SetTemperatureCurrent(Sensors[i]);			//Опрашиваем датчик
				CurrentValue = DinBase->GetTemperatureCurrent();	//Получаем значение с датчика и записываем в поле текущее значение
				cout << endl << "Текущее значение температуры: " << CurrentValue;
				//Если температура больше чем должна быть
				if (CurrentValue > Database->GetInformation(temperatureMax))
				{
					//cout << endl << "Максимально допустимое значение температуры: " << Database->GetInformation(temperatureMax);
					Decorators[0]->DoWrite();
					cout << Database->GetInformation(temperatureMax);
					cout << endl << "Температура больше чем должна быть ";
					//Перебираем прикладные объекты чтобы найти нужный
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Start();
							cout << endl << "Включаем вентилятор";
						}
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Finish();
							cout << endl << "Закрываем окно";
						}
					}
				}
				//Если температура меньше чем должна быть
				if (CurrentValue < Database->GetInformation(temperatureMin))
				{
					//cout << endl << "Минимально допустимое значение температуры: " << Database->GetInformation(temperatureMin);
					Decorators[1]->DoWrite();
					cout << Database->GetInformation(temperatureMin);
					cout << endl << "Температура меньше чем должна быть ";
					//Перебираем прикладные объекты чтобы найти нужный
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Start();
							cout << endl << "Открываем окно";
						}
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Finish();
							cout << endl << "Выключаем вентилятор";
						}
					}
				}
			}
			else
			{
				if (Sensors[i]->GiveName() == "HumiditySensor")
				{
					DinBase->SetHumidityCurrent(Sensors[i]);		//Опрашиваем датчик
					CurrentValue = DinBase->GetHumidityCurrent();	//Получаем значение с датчика и записываем в поле текущее значение
					cout << endl << "Текущее значение влажности: " << CurrentValue;
					//Если влажность больше чем должна быть 
					if (CurrentValue > Database->GetInformation(humidityMax))
					{
						//cout << endl << "Максимально допустимое значение влажности: " << Database->GetInformation(humidityMax);
						Decorators[2]->DoWrite();
						cout << Database->GetInformation(humidityMax);
						cout << endl << "Влажность больше чем должна быть ";
						//Перебираем прикладные объекты чтобы найти нужный
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Start();
								cout << endl << "Открываем окно";
							}
						}
					}
					//Если влажность меньше чем должна быть
					if (CurrentValue < Database->GetInformation(humidityMin))
					{
						//cout << endl << "Минимально допустимое значение влажности: " << Database->GetInformation(humidityMin);
						Decorators[3]->DoWrite();
						cout << Database->GetInformation(humidityMin);
						cout << endl << "Влажность меньше чем должна быть ";
						//Перебираем прикладные объекты чтобы найти нужный
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Finish();
								cout << endl << "Закрываем окно";
							}
						}
						//Перебираем системы полива чтобы найти нужную
						for (int i = 0; i < NSystem; i++) {
							if (Systems[i]->GiveSystemType() == "WaterReservoir") {
								if (Systems[i]->StartWatering(5) == true)
								{
									cout << endl << "Пошел полив растений";
								}
								else
								{
									cout << endl << "Не хватило воды";
								};
							}
						}
					}
				}
				else
				{
					if (Sensors[i]->GiveName() == "LightingSensor")
					{
						DinBase->SetLightingCurrent(Sensors[i]);	 //Опрашиваем датчик
						CurrentValue = DinBase->GetLightingCurrent();//Получаем значение с датчика и записываем в поле текущее значение
						cout << endl << "Текущее значение освещенности: " << CurrentValue;
						//Если освещенность больше чем должна быть 
						if (CurrentValue > Database->GetInformation(lightingMax))
						{
							//cout << endl << "Максимально допустимое значение освещенности: " << Database->GetInformation(lightingMax);
							Decorators[4]->DoWrite();
							cout << Database->GetInformation(lightingMax);
							cout << endl << "Освещенность больше чем должна быть ";
							//Перебираем прикладные объекты чтобы найти нужный
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Finish();
									cout << endl << "Выключаем лампу";
								}
							}
						}
						//Если освещенность меньше чем должна быть
						if (CurrentValue < Database->GetInformation(lightingMin))
						{
							//cout << endl << "Минимально допустимое значение освещенности: " << Database->GetInformation(lightingMin);
							Decorators[5]->DoWrite();
							cout << Database->GetInformation(lightingMin);
							cout << endl << "Освещенность меньше чем должна быть ";
							//Перебираем прикладные объекты чтобы найти нужный
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Start();
									cout << endl << "Включаем лампу";
								}
							}
						}
					}
					else
					{
						//Ничего не делать
					}
				}
			}
		}
		root.Mix();
		compositeCounter--;
		root.Remove(nutrients[compositeCounter]);
		
		//После этого выжидаем какое-то время и повторяем заново
		//sleep_until(system_clock::now() + seconds(1));
		Counter--;
		if (Counter <= 0)
		{
			Working = false;
		}
	} while (Working == true);
}