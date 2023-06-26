#pragma once
#include "Unit.h"

//Primitives 
class Passenger : public Unit
{
public:
	//место в самолете
	Passenger(int weight, pair<int, int> place)
	{
		row = place.first;
		position = place.second;		
		this->weight = weight;
		info();
	};
	int getWeight() const override { return weight; }
	void setWeight(int weight) { this->weight = weight; }
	void info() {		
		if (this->weight == 0)
			cout << endl << "Add passenger with baggage dropped" << endl;
		else
			cout << "Add passenger with weight=" << weight << endl;		
	}
};

class Pilot : public Unit
{
public:
	Pilot() { cout << "Pilot is added\n"; }
	int getWeight() const override { return 0; }
};

//стюардессы
class Stewardess : public Unit
{
public:
	Stewardess() { cout << "Stewardess is added\n"; }
	int getWeight() const override { return 0; }
};