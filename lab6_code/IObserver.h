#pragma once
#include <iostream>;
#include "Report.h" 
//наблюдатель
class IObserver {
public:
	virtual void Update(Rep rp) {};
};
