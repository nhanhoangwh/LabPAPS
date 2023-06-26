#pragma once

#include <iostream>

enum class Lisence { None, BCategory, DCategory };

class driver{
public:
	Lisence lisense=Lisence::None;
	driver() {
		std::cout << "Driver is created " << std::endl;
	}
};

class taxiDriver : public driver {
public:	 
	taxiDriver() {
		
		std::cout << "Taxi driver is created " << std::endl;
		lisense = Lisence::BCategory;
	}
};

class busDriver : public driver {
public:	 
	busDriver() {
		
		std::cout << "Bus driver is created " << std::endl;
		lisense = Lisence::DCategory;
	}
};

