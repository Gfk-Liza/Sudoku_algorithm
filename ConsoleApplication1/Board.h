#pragma once
#include "constants.h"
#include <iostream>
#include "Coordinate.h"

class Board
{
private:
	unsigned int board[BOARD_SIZE][BOARD_SIZE];
	bool is_vaild_x(const Coordinate xy, const unsigned int value) const;  // x座標固定 この関数はCoordinateが配列の範囲内であるかどうかを検証しない。
	bool is_vaild_y(const Coordinate xy, const unsigned int value) const;  // y座標固定 この関数はCoordinateが配列の範囲内であるかどうかを検証しない。
	bool is_vaild_group(const Coordinate xy, const unsigned int value) const;  // group固定 この関数はCoordinateが配列の範囲内であるかどうかを検証しない。
public:
	Board();
	unsigned int get(const Coordinate xy) const;  // この関数はCoordinateが配列の範囲内であるかどうかを検証しない。
	
	bool is_empty(const Coordinate xy) const;  // この関数はCoordinateが配列の範囲内であるかどうかを検証しない。
	bool is_valid(const Coordinate xy, const unsigned int value) const;  // この関数はCoordinateが配列の範囲内であるかやその場所か空白であるかを検証しない。
	void print() const;
	void set(const Coordinate xy, const unsigned int value);  // この関数はCoordinateが配列の範囲内であるかどうかを検証しない。
	void erase(const Coordinate xy);  // この関数はCoordinateが配列の範囲内であるかどうかを検証しない。

	friend bool operator==(const Board& a, const Board& b);
	friend bool operator!=(const Board& a, const Board& b);

	Board copy() const;
};

