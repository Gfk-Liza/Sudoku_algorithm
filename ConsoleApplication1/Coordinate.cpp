#include "Coordinate.h"

Coordinate::Coordinate()
{
	this->x = 0;
	this->y = 0;
}

Coordinate::Coordinate(const int new_x, const int new_y)
{
	this->x = new_x;
	this->y = new_y;
}

int Coordinate::getx() const
{
	return this->x;
}

int Coordinate::gety() const
{
	return this->y;
}

Coordinate Coordinate::get_group() const
{
	return Coordinate(this->x / 3 * 3, this->y / 3 * 3);
}

void Coordinate::increase()
{
	++this->x;
	if (this->x >= BOARD_SIZE) {
		this->x = 0;
		++this->y;
	}
}

void Coordinate::decrease()
{
	--this->x;
	if (this->x < 0) {
		this->x = BOARD_SIZE - 1;
		--this->y;
	}
}

bool Coordinate::is_valid() const
{
	return this->x < BOARD_SIZE && this->y < BOARD_SIZE && this->x >= 0 && this-> y >= 0;
}

void Coordinate::print() const
{
	std::cout << "y=" << this->y << ", x=" << this->x << std::endl;
}

int Coordinate::get_group_number() const
{
	return this->x / GROUP_SIZE + this->y / GROUP_SIZE * GROUP_SIZE;
}
