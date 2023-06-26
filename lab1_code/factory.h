#pragma once
#pragma once
#include "driver.h"
#include "board.h"
#include <iostream>

class abstractFactory
{
public:
	virtual driver* createDriver() = 0;
	virtual boardAnyCar* createBoard() = 0;
};

class busFactory : public abstractFactory
{
public:
	busDriver* createDriver() override {
		return new busDriver();
	};
	boardBus* createBoard() override {
		return new boardBus();
	};
};

class taxiFactory : public abstractFactory
{
public:
	taxiDriver* createDriver() override {
		return new taxiDriver();
	};
	boardTaxi* createBoard() override {
		return new boardTaxi();
	};
};
