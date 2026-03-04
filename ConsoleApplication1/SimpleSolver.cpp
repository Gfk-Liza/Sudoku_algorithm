#include "SimpleSolver.h"

bool SimpleSolver::solve_dfs(Coordinate xy)
{
	if (!xy.is_valid()) return true;
	if (!this->board.is_empty(xy)) {
		xy.increase();
		return this->solve_dfs(xy);
	}
	Coordinate next_xy = xy;
	next_xy.increase();
	for (unsigned int i = 1; i <= NUMBERS; ++i) {
		if (!this->board.is_valid(xy, i)) continue;
		this->board.set(xy, i);
		if (this->solve_dfs(next_xy)) return true;
		this->board.erase(xy, i);
	}
	return false;
}

bool SimpleSolver::reverse_solve_dfs(Coordinate xy)
{
	if (!xy.is_valid()) return true;
	if (!this->board.is_empty(xy)) {
		xy.increase();
		return this->reverse_solve_dfs(xy);
	}
	Coordinate next_xy = xy;
	next_xy.increase();
	for (unsigned int i = NUMBERS; i > 0; --i) {
		if (!this->board.is_valid(xy, i)) continue;
		this->board.set(xy, i);
		if (this->reverse_solve_dfs(next_xy)) return true;
		this->board.erase(xy, i);
	}
	return false;
}

void SimpleSolver::solve()
{
	this->solve_dfs(Coordinate());
}

void SimpleSolver::reverse_solve()
{
	this->reverse_solve_dfs(Coordinate());
}
