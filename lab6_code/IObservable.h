#pragma once
#include "IObserver.h"
// ���������, �������������� ����������� ������ 
class IObservable {
public:
	virtual void Attach(IObserver io) {};
	virtual void Detach(IObserver io) {};
	virtual void Notify() {}; //���������
};