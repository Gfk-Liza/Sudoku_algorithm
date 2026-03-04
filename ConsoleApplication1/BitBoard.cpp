#include "BitBoard.h"

unsigned int BitBoard::get_groupmask(const int group_number) const
{
	switch (group_number % 3 ) {
	case 0:
		return 117670336;
	case 1:
		return 14708792;
	case 2:
		return 1838599;
	}
}

BitBoard::BitBoard()
{
	this->bit_board[0] = 0;
	this->bit_board[1] = 0;
	this->bit_board[2] = 0;
}

bool BitBoard::is_valid(const Coordinate xy) const
{
	if ((this->bit_board[xy.gety() / GROUP_SIZE] & (511 << (xy.gety() % GROUP_SIZE * 9))) != 0) return false;  // y座標固定

	if ((this->bit_board[xy.gety() / GROUP_SIZE] & this->get_groupmask(xy.get_group_number())) != 0) return false;  // group固定

	// 以下x座標固定
	unsigned int mask_x = 1 << xy.getx();
	mask_x |= mask_x << 18 | mask_x << 9;
	if ((this->bit_board[0] & mask_x) != 0) return false;
	if ((this->bit_board[1] & mask_x) != 0) return false;
	if ((this->bit_board[2] & mask_x) != 0) return false;

	return true;
}

void BitBoard::set(const Coordinate xy)
{
	this->bit_board[xy.gety() / GROUP_SIZE] |= 1 << (xy.getx() + xy.gety() / 3 * 3);
}

void BitBoard::erase(const Coordinate xy)
{
	this->bit_board[xy.gety() / GROUP_SIZE] &= !(1 << (xy.getx() + xy.gety() / 3 * 3));
}

