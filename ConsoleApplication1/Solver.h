#pragma once
#include "Board.h"
#include "Coordinate.h"

class Solver
{
protected:
	Board board;
public:
	Solver();
	void set(const Board& new_board);
	Board get()const;
};

