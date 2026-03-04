#pragma once
#include "constants.h"

class BitBoard
{
private:
	bool bitboard[BOARD_SIZE][BOARD_SIZE];

public:
	BitBoard();  // falseはなし, trueはあり
};

