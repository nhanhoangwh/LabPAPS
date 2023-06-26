#pragma once
#include "builder.h"

class director {
public:
	boardAnyCar* createBoard(builder& builder, size_t numAdult, size_t numChild, size_t numDis)
	{
		builder.createBoard(); 
		builder.buildDriver();

		for (size_t i = 0; i <= numAdult; i++)
			builder.buildAdult();
		for (size_t i = 0; i <= numChild; i++)
			builder.buildChild();
		for (size_t i = 0; i <= numDis; i++)
			builder.buildDiscount();
		return builder.getBoard();
	}
};