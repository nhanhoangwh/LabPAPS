#include "director.h"

int main()
{
	director dir;
	busBuilder bus;
	taxiBuilder taxi;
	boardAnyCar* bbus = dir.createBoard(bus, 10, 3, 5);
	std::cout << std::endl;
	boardAnyCar* btaxi = dir.createBoard(taxi, 2, 2, 0);


	return 0;
}