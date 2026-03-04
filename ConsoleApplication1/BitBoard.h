#pragma once
#include "constants.h"
#include "Coordinate.h"

class BitBoard
{
private:
	unsigned int bit_board[3];
	//
	// bit_board対応表
	//  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8
	//  9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17
	// 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 27 (ここまでindex = 0)
	//  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8
	//  9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17
	// 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 27 (ここまでindex = 1)
	//  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8
	//  9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17
	// 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 27 (ここまでindex = 2)
	//

	unsigned int get_groupmask(const int group_number) const;

public:
	BitBoard();  // falseはなし, trueはあり

	bool is_valid(const Coordinate xy) const;

	void set(const Coordinate xy);
	void erase(const Coordinate xy);
};

