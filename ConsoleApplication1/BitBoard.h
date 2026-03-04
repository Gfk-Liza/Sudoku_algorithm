#pragma once
#include "constants.h"
#include "Coordinate.h"

class BitBoard
{
private:
	unsigned int bit_board[3];
	//
	// bit_board mapping:
	//  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8
	//  9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17
	// 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 (end of index = 0)
	//  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8
	//  9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17
	// 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 (end of index = 1)
	//  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8
	//  9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17
	// 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 (end of index = 2)
	//

public:
	BitBoard();  // false = none, true = present
	BitBoard(const unsigned int a, const unsigned int b, const unsigned int c);

	bool is_valid(const Coordinate xy) const;

	void set(const Coordinate xy);
	void erase(const Coordinate xy);
	bool does_exist(const Coordinate xy) const;
	BitBoard copy() const;


	friend bool operator==(const BitBoard& a, const BitBoard& b);
	friend bool operator!=(const BitBoard& a, const BitBoard& b);
};

