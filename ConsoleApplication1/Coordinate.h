#pragma once
#include "constants.h"
#include <iostream>

class Coordinate
{
private:
	int xy;

public:
	Coordinate();
	Coordinate(const int new_x, const int new_y);
	Coordinate(const int new_xy);

	int getx() const;
	int gety() const;
	void increase();
	void decrease();
	bool is_valid() const;
	void print() const;
	int get_bitboard_index() const;

	unsigned int get_bitboard_x_mask() const;
	unsigned int get_bitboard_y_mask() const;
	unsigned int get_bitboard_group_mask() const;
	unsigned int get_bitboard_spesific_mask() const;
};

