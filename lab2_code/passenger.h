#pragma once
#include <iostream>


class childSeat { //Детское кресло
public:
	childSeat() {
		std::cout<<("Child seat added")<<std::endl;
	}
};

class passenger {};

class adult : public passenger
{
public:
	
	adult() {
		std::cout << "Adult passenger is created " << std::endl;
	}
};

class discount : public passenger //льготный
{
public:
	
	discount() {
		std::cout << "Discount passenger is created " << std::endl;
	}
};

class child : public passenger
{
public:
	childSeat* seat;	

	child() {
		std::cout << "Child passenger is created " << std::endl;
		seat = new childSeat;
	}
};

