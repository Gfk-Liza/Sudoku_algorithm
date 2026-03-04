#pragma once
#include "constants.h"
#include <iostream>
#include "Coordinate.h"
#include "BitBoard.h"

class Board
{
private:
	BitBoard bitboards[NUMBERS];
public:
	Board();
	unsigned int get(const Coordinate xy) const;  // This function does not check whether Coordinate is within array bounds.
	
	bool is_empty(const Coordinate xy) const;  // This function does not check whether Coordinate is within array bounds.
	bool is_valid(const Coordinate xy, const unsigned int value) const;  // This function does not check whether Coordinate is within array bounds or whether the cell is empty.
	void print() const;
	void set(const Coordinate xy, const unsigned int value);  // This function does not check whether Coordinate is within array bounds. Also assumes value != 0
	void erase(const Coordinate xy, const unsigned int value);  // This function does not check whether Coordinate is within array bounds. Also assumes value != 0
	void erase(const Coordinate xy);  // This function does not check whether Coordinate is within array bounds.

	friend bool operator==(const Board& a, const Board& b);
	friend bool operator!=(const Board& a, const Board& b);

	Board copy() const;
};

