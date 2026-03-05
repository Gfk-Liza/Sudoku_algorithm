#pragma once
#include "Solver.h"
#include "Board.h"
#include "Coordinate.h"

class SimpleSolver :
    public Solver
{
private:
    bool solve_dfs(Coordinate xy);
    bool reverse_solve_dfs(Coordinate xy);
public:
    void solve();  // 単純なDFSで解く
    void reverse_solve();
};

