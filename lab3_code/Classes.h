#pragma once
#include "Passengers.h"

class CompositeFirstClass : public Unit
{
public:
	CompositeFirstClass(pair<int, int> size)
	{
		row = size.first;
		position = size.second;
	}
	int getWeight() const override
	{
		weight = 0;
		for (const auto& v : uni)
			weight += v.second->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		if (uni.size() <= FullPassengers::FirstPass)
			uni[make_pair(u->getRow(), u->getPos())] = u;
		//else
			//throw new UnitOverflowException();
	}
	~CompositeFirstClass()
	{
		for (const auto& c : uni)
			delete c.second;
	}
	const map<pair<int, int>, Unit*>& getUnits() const override { return uni; }
};

class CompositeEconomClass : public Unit
{
public:
	CompositeEconomClass(pair<int, int> size)
	{
		row = size.first;
		position = size.second;
	}
	int getWeight() const override
	{
		weight = 0;
		for (const auto& v : uni)
			weight += v.second->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		if (uni.size() < FullPassengers::EconomPass)
			uni[make_pair(u->getRow(), u->getPos())] = u;
		//else
			//throw new UnitOverflowException();
	}
	~CompositeEconomClass()
	{
		for (const auto& c : uni)
			delete c.second;
	}
	const map<pair<int, int>, Unit*>& getUnits() const override { return uni; }
};

class CompositeBusinessClass : public Unit
{
public:
	CompositeBusinessClass(pair<int, int> size)
	{
		row = size.first;
		position = size.second;
	}
	int getWeight() const override
	{
		weight = 0;
		for (const auto& v : uni)
			weight += v.second->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		if (uni.size() < FullPassengers::BusinessPass)
			uni[make_pair(u->getRow(), u->getPos())] = u;
		//else
		//	throw new UnitOverflowException();
	}
	~CompositeBusinessClass()
	{
		for (const auto& c : uni)
			delete c.second;
	}
	const map<pair<int, int>, Unit*>& getUnits() const override { return uni; }
};
