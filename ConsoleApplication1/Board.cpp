
#include "Board.h"

bool Board::is_vaild_x(const Coordinate xy, const unsigned int value) const
{
	int tmp = xy.getx();
	for (int i = 0; i < BOARD_SIZE; ++i) {
		if (value == this->board[i][tmp]) return false;
	}
	return true;
}

bool Board::is_vaild_y(const Coordinate xy, const unsigned int value) const
{
	int tmp = xy.gety();
	for (int i = 0; i < BOARD_SIZE; ++i) {
		if (value == this->board[tmp][i]) return false;
	}
	return true;
}

bool Board::is_vaild_group(const Coordinate xy, const unsigned int value) const
{
	const Coordinate tmp = xy.get_group();
	const unsigned int i_max = static_cast<unsigned int>(tmp.gety()) + GROUP_SIZE;
	const unsigned int j_init = static_cast<unsigned int>(tmp.getx());
	const unsigned int j_max = j_init + GROUP_SIZE;
	unsigned int i, j;
	for (i = static_cast<unsigned int>(tmp.gety()); i < i_max; ++i) {
		for (j = j_init; j < j_max; ++j) {
			if (value == this->board[i][j]) return false;
		}
	}
	return true;
}

bool Board::is_empty(const Coordinate xy) const
{
	return this->get(xy) == 0;
}



Board::Board()
{
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			this->board[i][j] = 0;
		}
	}
}

unsigned int Board::get(const Coordinate xy) const
{
	return this->board[xy.gety()][xy.getx()];
}

bool Board::is_valid(const Coordinate xy, const unsigned int value) const
{
	if (!this->is_vaild_y(xy, value)) return false;
	if (!this->is_vaild_x(xy, value)) return false;
	if (!this->is_vaild_group(xy, value)) return false;
	return true;
}

void Board::print() const
{
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			if (this->board[i][j] == 0) {
				std::cout << "_ ";
			}
			else {
				std::cout << this->board[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
}

void Board::set(const Coordinate xy, const unsigned int value)
{
	this->board[xy.gety()][xy.getx()] = value;
}

void Board::erase(const Coordinate xy)
{
	this->board[xy.gety()][xy.getx()] = 0;
}

Board Board::copy() const
{
	Board tmp;
	for (unsigned int i = 0; i < BOARD_SIZE; ++i) {
		for (unsigned int j = 0; j < BOARD_SIZE; ++j) {
			tmp.board[i][j] = this->board[i][j];
		}
	}
	return tmp;
}

bool operator==(const Board& a, const Board& b)
{
	for (unsigned int i = 0; i < BOARD_SIZE; ++i) {
		for (unsigned int j = 0; j < BOARD_SIZE; ++j) {
			if (a.board[i][j] != b.board[i][j]) return false;
		}
	}
	return true;
}

bool operator!=(const Board& a, const Board& b)
{
	return !(a == b);
}
