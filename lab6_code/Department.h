#pragma once
#include "Progress.h"
#include <vector>


class Department :IObserver {
public:
	Progess* prg;
	std::vector<Rep> db;

	Department(Progess* pro) {
		this->prg = pro;
		pro->Attach(this);
	}

	void Update(Rep rp) {
		db.push_back(rp);
		if (rp == Rep::nonCreated) {
			std::cout << "Teacher " << (prg)->teacher->name << " have not report " << std::endl;
		}
	}

	

};
