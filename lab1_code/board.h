#include <iostream>
#include <vector>
#include "driver.h"
#include "passenger.h"
class boardAnyCar {
public:
	int maxPassenger=0;
	driver* driver1 = nullptr;
	vector <passenger*> listPassenger;

	bool isReady() {
		if (driver1 == nullptr) return false;
		if (listPassenger.size() < maxPassenger) return false;
		return true;
	};

	void boardDriver(driver* dri) {
		
		if (driver1 == nullptr)
		{
			driver1 = dri;
			cout << "Driver in car" << endl;
		}
	};

	void boardPassenger(passenger* pas) {
		if (listPassenger.size() <= maxPassenger)
		{
			listPassenger.push_back(pas);
			cout << "Add 1 passenger" << endl;
		}
		else
			cout << "Full" << endl;
	};
};

class boardTaxi : public boardAnyCar {
public:
	boardTaxi() {
		maxPassenger = 4;
		cout << "Board taxi is created" << endl;
	};
};

class boardBus : public boardAnyCar {
public:
	boardBus() {
		maxPassenger = 30;
		cout << "Board bus is created" << endl;
	};
};