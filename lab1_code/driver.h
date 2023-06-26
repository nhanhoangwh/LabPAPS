#pragma once
#include <iostream>
#include <string>

using namespace std;

class driver
{
public:
	string lisence;
};

class taxiDriver : public driver
{
public:
	taxiDriver() {
		cout << "Taxi driver is created" << endl;
		lisence = "BCategory";
	};
};

class busDriver : public driver
{
public:
	busDriver() {
		cout << "Bus driver is created" << endl;
		lisence = "DCategory";
	};
};
