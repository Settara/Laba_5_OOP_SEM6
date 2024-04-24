#include "IGMS.h"

void IGMS::Management(IDynamicDatabase* DinBase, ProxyDatabase* Database, ISensor* Sensors[NSensors], IAO* Objects[NObjects], IIS* Systems[NSystem], Decorator* Decorators[NDecorators])
{
	//�������� ������� ��� ������������ 
	int compositeCounter = 3;
	//������� ����������� � ��� ������
	Composite root;
	//������� ������ ���������� ��� ����� ��������� ��� ������
	Nutrients* nutrients[NNutrients];
	nutrients[0] = new Humus();
	nutrients[1] = new Humus();
	nutrients[2] = new Peat();
	//������� ������ ������� �����������
	Composite embededComposition;
	nutrients[3] = new Humus();
	nutrients[4] = new Peat();
	//��������� ������ anower ��������
	embededComposition.Add(nutrients[3]);
	embededComposition.Add(nutrients[4]);
	//��������� ������� � root
	root.Add(nutrients[0]);
	root.Add(&embededComposition);
	root.Add(nutrients[1]);
	root.Add(nutrients[2]);

	//������� ����������� ������� ������ 
	Node *node1, *node2, *node3;
	node1 = new Node();
	node2 = new Node();
	node3 = new Node();
	//��������� ������
	node1->item = 1;
	node2->item = 2;
	node3->item = 3;
	node1->p_next = node2;
	node2->p_next = node3;
	//������� ��������
	Iterator* iterator = new Iterator(node1);
	//������ ��� �� �� ����� ��� �����
	cout << endl << "��� ����� � Node: " << iterator->operator*() << " ";
	//���������� ��������
	iterator->operator++();
	//������ ��� �� �� ����� ��� �����
	cout << endl << "��� ����� � Node: " << iterator->operator*() << " ";
	

	//��� ������ ����� �������� ��� ������� ����� ������ ������� ��������� 
	do
	{
		for (int i = 0; i < NSensors; i++) {
			if (Sensors[i]->GiveName() == "TemperatureSensor")
			{
				DinBase->SetTemperatureCurrent(Sensors[i]);			//���������� ������
				CurrentValue = DinBase->GetTemperatureCurrent();	//�������� �������� � ������� � ���������� � ���� ������� ��������
				cout << endl << "������� �������� �����������: " << CurrentValue;
				//���� ����������� ������ ��� ������ ����
				if (CurrentValue > Database->GetInformation(temperatureMax))
				{
					//cout << endl << "����������� ���������� �������� �����������: " << Database->GetInformation(temperatureMax);
					Decorators[0]->DoWrite();
					cout << Database->GetInformation(temperatureMax);
					cout << endl << "����������� ������ ��� ������ ���� ";
					//���������� ���������� ������� ����� ����� ������
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Start();
							cout << endl << "�������� ����������";
						}
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Finish();
							cout << endl << "��������� ����";
						}
					}
				}
				//���� ����������� ������ ��� ������ ����
				if (CurrentValue < Database->GetInformation(temperatureMin))
				{
					//cout << endl << "���������� ���������� �������� �����������: " << Database->GetInformation(temperatureMin);
					Decorators[1]->DoWrite();
					cout << Database->GetInformation(temperatureMin);
					cout << endl << "����������� ������ ��� ������ ���� ";
					//���������� ���������� ������� ����� ����� ������
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Start();
							cout << endl << "��������� ����";
						}
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Finish();
							cout << endl << "��������� ����������";
						}
					}
				}
			}
			else
			{
				if (Sensors[i]->GiveName() == "HumiditySensor")
				{
					DinBase->SetHumidityCurrent(Sensors[i]);		//���������� ������
					CurrentValue = DinBase->GetHumidityCurrent();	//�������� �������� � ������� � ���������� � ���� ������� ��������
					cout << endl << "������� �������� ���������: " << CurrentValue;
					//���� ��������� ������ ��� ������ ���� 
					if (CurrentValue > Database->GetInformation(humidityMax))
					{
						//cout << endl << "����������� ���������� �������� ���������: " << Database->GetInformation(humidityMax);
						Decorators[2]->DoWrite();
						cout << Database->GetInformation(humidityMax);
						cout << endl << "��������� ������ ��� ������ ���� ";
						//���������� ���������� ������� ����� ����� ������
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Start();
								cout << endl << "��������� ����";
							}
						}
					}
					//���� ��������� ������ ��� ������ ����
					if (CurrentValue < Database->GetInformation(humidityMin))
					{
						//cout << endl << "���������� ���������� �������� ���������: " << Database->GetInformation(humidityMin);
						Decorators[3]->DoWrite();
						cout << Database->GetInformation(humidityMin);
						cout << endl << "��������� ������ ��� ������ ���� ";
						//���������� ���������� ������� ����� ����� ������
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Finish();
								cout << endl << "��������� ����";
							}
						}
						//���������� ������� ������ ����� ����� ������
						for (int i = 0; i < NSystem; i++) {
							if (Systems[i]->GiveSystemType() == "WaterReservoir") {
								if (Systems[i]->StartWatering(5) == true)
								{
									cout << endl << "����� ����� ��������";
								}
								else
								{
									cout << endl << "�� ������� ����";
								};
							}
						}
					}
				}
				else
				{
					if (Sensors[i]->GiveName() == "LightingSensor")
					{
						DinBase->SetLightingCurrent(Sensors[i]);	 //���������� ������
						CurrentValue = DinBase->GetLightingCurrent();//�������� �������� � ������� � ���������� � ���� ������� ��������
						cout << endl << "������� �������� ������������: " << CurrentValue;
						//���� ������������ ������ ��� ������ ���� 
						if (CurrentValue > Database->GetInformation(lightingMax))
						{
							//cout << endl << "����������� ���������� �������� ������������: " << Database->GetInformation(lightingMax);
							Decorators[4]->DoWrite();
							cout << Database->GetInformation(lightingMax);
							cout << endl << "������������ ������ ��� ������ ���� ";
							//���������� ���������� ������� ����� ����� ������
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Finish();
									cout << endl << "��������� �����";
								}
							}
						}
						//���� ������������ ������ ��� ������ ����
						if (CurrentValue < Database->GetInformation(lightingMin))
						{
							//cout << endl << "���������� ���������� �������� ������������: " << Database->GetInformation(lightingMin);
							Decorators[5]->DoWrite();
							cout << Database->GetInformation(lightingMin);
							cout << endl << "������������ ������ ��� ������ ���� ";
							//���������� ���������� ������� ����� ����� ������
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Start();
									cout << endl << "�������� �����";
								}
							}
						}
					}
					else
					{
						//������ �� ������
					}
				}
			}
		}
		root.Mix();
		compositeCounter--;
		root.Remove(nutrients[compositeCounter]);
		
		//����� ����� �������� �����-�� ����� � ��������� ������
		//sleep_until(system_clock::now() + seconds(1));
		Counter--;
		if (Counter <= 0)
		{
			Working = false;
		}
	} while (Working == true);
}