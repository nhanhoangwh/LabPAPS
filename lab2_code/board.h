#pragma once
#include <iostream>
#include <vector>
#include "driver.h"
#include "passenger.h"

class boardAnyCar {
public:
	
	unsigned maxPassenger = 0;
	driver* dri = nullptr;
	std::vector <passenger*> listPassenger;

	bool isReady() {
		if (dri == nullptr) return false;
		if (listPassenger.size() < maxPassenger) return false;
		return true;
	}

	virtual void boardDriver() =0;

	void boardPassenger(passenger* pas)
	{
		if (listPassenger.size() <= maxPassenger)
		{
			listPassenger.push_back(pas);
			std::cout << "Add 1 passenger " << std::endl;
		}
		else
			std::cout << "Full " << std::endl;
	}
};

class boardTaxi :public boardAnyCar {
public:
	boardTaxi() {
		maxPassenger = 4;
		std::cout << "Board taxi is created " << std::endl;
	}

	void boardDriver() {
		dri = new taxiDriver;
	}
};

class boardBus :public boardAnyCar {
public:
	boardBus() {
		maxPassenger = 30;
		std::cout << "Board bus is created " << std::endl;
	}
	void boardDriver() {
		dri = new busDriver;
	}
};