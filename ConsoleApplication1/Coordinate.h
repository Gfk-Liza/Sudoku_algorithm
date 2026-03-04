#pragma once
#include "constants.h"
#include <iostream>

class Coordinate
{
private:
	int x, y;
public:
	Coordinate();
	Coordinate(const int new_x, const int new_y);

	int getx() const;
	int gety() const;
	Coordinate get_group() const;  // その座標が属するgroup（数独の正方形集合）の主座標（左上の座標）を返す。
	void increase();
	void decrease();
	bool is_valid() const;
	void print() const;
	int get_group_number() const;
};

