#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <memory>
using namespace std;

//Component
class Unit {
	protected:
		map<pair<int, int>, Unit*> uni;
		int mutable weight; //масса
		int row; //место в самолете
		int position;
	public:
		virtual int getWeight() const = 0;
		virtual	void addUnit(Unit*) {};
		virtual void deleteUnit(pair<int, int>) {};
		virtual int getRow() const { return row; }
		virtual int getPos() const { return position; }
		virtual const map<pair<int, int>, Unit*>& getUnits() const { return uni; }
};

enum FullPassengers { EconomPass = 150, BusinessPass = 20, FirstPass = 10 };
enum FullWeight { EconomWeight = 20, BusinessWeight = 35, MaxWeight = 60, MinWeight = 5 };
enum Ticket { Row = 50, Position = 6 };