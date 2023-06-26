#include "Department.h"

int main() {
	Teacher tch("Nhan");
	Progess p(&tch);
	Department d(&p);

	//p.Reported();

	//week 1
	p.NonReported();
	//week 2
	p.NonReported();
	//week 3
	p.Reported();

	std::vector<Rep>::iterator iter = d.db.begin();

	while ( iter != d.db.end())
	{
		std::cout << static_cast<int>( *iter)<<" ";
		iter++;
	}

	

	
}