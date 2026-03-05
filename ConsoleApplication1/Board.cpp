
#include "Board.h"

bool Board::is_empty(const Coordinate xy) const
{
	return this->get(xy) == 0;
}



Board::Board()
{
	for (int i = 0; i < NUMBERS; ++i) {
		this->bitboards[i] = BitBoard();
	}
}

unsigned int Board::get(const Coordinate xy) const
{
	for (int i = 0; i < NUMBERS; ++i) {
		if (this->bitboards[i].does_exist(xy)) return i + 1;
	}
	return 0;
}

bool Board::is_valid(const Coordinate xy, const unsigned int value) const
{
	return this->bitboards[value - 1].is_valid(xy);
}

void Board::print() const
{
	for (int i = 0; i < CELL_NUMBER; ++i) {
		int tmp = this->get(Coordinate(i));
		if (tmp == 0) std::cout << "_ ";
		else std::cout << tmp << " ";
		if (i % BOARD_SIZE == BOARD_SIZE - 1) std::cout << std::endl;
	}
}

void Board::set(const Coordinate xy, const unsigned int value)
{
	this->bitboards[value - 1].set(xy);
}

void Board::erase(const Coordinate xy, const unsigned int value)
{
	this->bitboards[value - 1].erase(xy);
}

void Board::erase(const Coordinate xy)
{
	for (int i = 0; i < NUMBERS; ++i) {
		this->bitboards[i].erase(xy);
	}
}

Board Board::copy() const
{
	Board tmp;
	for (unsigned int i = 0; i < NUMBERS; ++i) {
		tmp.bitboards[i] = this->bitboards[i].copy();
	}
	return tmp;
}

bool operator==(const Board& a, const Board& b)
{
	for (unsigned int i = 0; i < NUMBERS; ++i) {
		if (a.bitboards[i] != b.bitboards[i]) return false;
	}
	return true;
}

bool operator!=(const Board& a, const Board& b)
{
	return !(a == b);
}
