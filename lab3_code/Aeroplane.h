#pragma once
#include "Classes.h"

class Aeroplane : public Unit
{
	unique_ptr<CompositeBusinessClass> business;
	unique_ptr<CompositeEconomClass> econom;
	unique_ptr<CompositeFirstClass> first;
	vector<Stewardess*> stewardesses;
	vector<Pilot*> pilots;
	static const int maxWeight = 500;
public:
	Aeroplane(size_t economPass, size_t businessPass, size_t firstPass)
	{
		weight = 0;
		int r = 0; int p = 0;
		cout << "Aeroplane is created\n";

		for (size_t i = 0; i < 2; i++)
			pilots.push_back(new Pilot());

		for (size_t i = 0; i < 6; i++)
			stewardesses.push_back(new Stewardess());

		cout << "----------FirstClass----------" << endl;
		first = make_unique<CompositeFirstClass>(make_pair<int, int>(Ticket::Row, Ticket::Position));
		for (size_t i = 0; i < firstPass; i++)
		{
			p = p++ % Ticket::Position + 1;
			pair<int, int> pr = { p == 0 ? ++r : r ,p };
			int weightFirst = rand() % (FullWeight::MaxWeight - FullWeight::MinWeight) + FullWeight::MinWeight;
			first->addUnit(new Passenger(weightFirst,pr));
		}
		cout << endl;
		cout << "----------BusinessClass----------" << endl;
		business = make_unique<CompositeBusinessClass>(make_pair<int, int>(Ticket::Row, Ticket::Position));
		for (size_t i = 0; i < businessPass; i++)
		{
			p = p++ % Ticket::Position + 1;
			pair<int, int> pr = { p == 0 ? ++r : r ,p };
			int weightBus = rand() % (FullWeight::MaxWeight - FullWeight::MinWeight) + FullWeight::MinWeight;
			if (weightBus > FullWeight::BusinessWeight) weightBus = FullWeight::BusinessWeight;
			business->addUnit(new Passenger(weightBus,pr));
		}
			
		weight = business->getWeight() + first->getWeight();

		cout << endl;
		cout << "----------EconomClass----------" << endl;
		econom = make_unique<CompositeEconomClass>(make_pair<int, int>(Ticket::Row, Ticket::Position));
		if (weight >= maxWeight)
		{
			for (size_t i = 0; i < economPass; i++)
			{
				p = p++ % Ticket::Position + 1;
				pair<int, int> pr = { p == 0 ? ++r : r ,p };
				econom->addUnit(new Passenger(0,pr));
			}
				
		}
		else
		{
			static int rnd = 0;
			for (size_t i = 0; i < economPass; i++)
			{
				p = p++ % Ticket::Position + 1;
				pair<int, int> pr = { p == 0 ? ++r : r ,p };
				rnd = rand() % (FullWeight::MaxWeight - FullWeight::MinWeight) + FullWeight::MinWeight;
				if (rnd > FullWeight::EconomWeight) rnd = FullWeight::EconomWeight;
				if (weight + rnd > maxWeight)
				{
					econom->addUnit(new Passenger(0, pr));
				}
				else
				{
					weight += rnd;
					econom->addUnit(new Passenger(rnd,pr));
				}

			}
		}
	}
	int getWeight() const override
	{
		return weight;
	}
	~Aeroplane()
	{
		for (auto& c : stewardesses)
			delete c;
		stewardesses.clear();
		stewardesses.shrink_to_fit();
		for (auto& c : pilots)
			delete c;
		pilots.clear();
		pilots.shrink_to_fit();
	}
};