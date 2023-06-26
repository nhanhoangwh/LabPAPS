#pragma once
#include "IObservable.h"
#include "Teacher.h"

//� ������� ������� ����� ��������
class Progess : IObservable {
public:
	Teacher* teacher;
	IObserver* observer = nullptr;
	Rep rp=Rep::non;

	Progess(Teacher* t) {
		this->teacher = t;
	}

	void Attach(IObserver* o) {
		if (observer == nullptr)
			observer = o;
	}

	void Detach(IObserver* o) {
		observer = nullptr;
	}

	void Notify() {
		observer->Update(rp);
	}

	//������� ������� ������������
	void Reported(){
		rp = Rep::created;
		Notify();
	}

	void NonReported() {
		rp = Rep::nonCreated;
		Notify();
	}
	

};