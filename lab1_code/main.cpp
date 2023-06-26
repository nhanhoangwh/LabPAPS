#include <iostream>
#include <string>
#include "factory.h"
#include "passenger.h"
using namespace std;

int main() {

	int choice = 0;
	if (choice == 1) //bus
	{
		busFactory* factory = new busFactory;
		boardBus* bbus = (factory)->createBoard();
		busDriver* dbus = (factory)->createDriver();
		bbus->boardDriver(dbus);
		int count = 0;
		for (int i = 0; i < bbus->maxPassenger; i++)
		{
			passenger* p = new passenger();
			bbus->boardPassenger(p);
		}
		cout << bbus->isReady() << endl;
		system("pause");
	}
	else //taxi
	{
		taxiFactory* factory = new taxiFactory;
		boardTaxi* btaxi = (factory)->createBoard();
		taxiDriver* dtaxi = (factory)->createDriver();
		btaxi->boardDriver(dtaxi);
		int count = 0;
		for (int i = 0; i <= btaxi->maxPassenger + 1; i++)
		{
			passenger* p = new passenger();
			btaxi->boardPassenger(p);
		}

		cout << btaxi->isReady()<<"- ready"<<endl;
		delete factory;
		delete btaxi;
		delete dtaxi;
		system("pause");
	}
}