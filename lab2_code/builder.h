#pragma once
#include "board.h"

class builder {
protected: boardAnyCar *board;
public:
	builder(): board(nullptr){}

	virtual void createBoard() = 0;
	virtual void buildAdult() = 0;
	virtual void buildDiscount() = 0;
	virtual void buildChild() = 0;
	virtual void buildDriver() = 0;

	boardAnyCar* getBoard() {
		return board;
	}

};

class taxiBuilder :public builder {
	void createBoard() {
		board = new boardTaxi;
	}

	void buildDriver() {
		board->boardDriver();
	}

	void buildChild() {
		board->boardPassenger(new child());
	} // ребенок

	void buildAdult() {
		board->boardPassenger(new adult());
	} // взрослый

	void buildDiscount() {};  //льготный
};

class busBuilder :public builder {
	void createBoard() {
		board = new boardBus;
	}

	void buildDriver() {
		board->boardDriver();
	}

	void buildChild() {
		board->boardPassenger(new child());
	}

	void buildAdult() {
		board->boardPassenger(new adult());
	}

	void buildDiscount() {
		board->boardPassenger(new discount());
	}
};

