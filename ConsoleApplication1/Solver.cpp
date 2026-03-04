#include "Solver.h"

Solver::Solver()
{
	this->board = Board();
}

void Solver::set(const Board& new_board)
{
	this->board = new_board.copy();
}

Board Solver::get() const
{
	return this->board.copy();
}
