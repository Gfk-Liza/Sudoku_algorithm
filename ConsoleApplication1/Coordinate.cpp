#include "Coordinate.h"

Coordinate::Coordinate()
{
	this->xy = 0;
}

Coordinate::Coordinate(const int new_x, const int new_y)
{
	this->xy = new_x + new_y * BOARD_SIZE;
}

Coordinate::Coordinate(const int new_xy)
{
	this->xy = new_xy;
}

int Coordinate::getx() const
{
	return this->xy % BOARD_SIZE;
}

int Coordinate::gety() const
{
	return this->xy / BOARD_SIZE;
}

void Coordinate::increase()
{
	++this->xy;
}

void Coordinate::decrease()
{
	--this->xy;
}

bool Coordinate::is_valid() const
{
	return this->xy < CELL_NUMBER && this->xy >= 0;
}

void Coordinate::print() const
{
	std::cout << "y=" << this->gety() << ", x=" << this->getx() << std::endl;
}

int Coordinate::get_bitboard_index() const
{
	return this->xy / 27;
}

unsigned int Coordinate::get_bitboard_y_mask() const
{
	return 511 << (this->xy / BOARD_SIZE % GROUP_SIZE * BOARD_SIZE);
}

unsigned int Coordinate::get_bitboard_x_mask() const
{
	switch (this->xy % 9) {
	case 0:
		return 262657;
	case 1:
		return 525314;
	case 2:
		return 1050628;
	case 3:
		return 2101256;
	case 4:
		return 4202512;
	case 5:
		return 8405024;
	case 6:
		return 16810048;
	case 7:
		return 33620096;
	case 8:
		return 67240192;
	}
	return 0;
}

unsigned int Coordinate::get_bitboard_group_mask() const
{
	switch (this->xy % BOARD_SIZE / GROUP_SIZE) {
	case 0:
		return 1838599;
	case 1:
		return 14708792;
	case 2:
		return 117670336;
	}
	return 0;
}

unsigned int Coordinate::get_bitboard_spesific_mask() const
{
	return 1 << this->xy % 27;
}

