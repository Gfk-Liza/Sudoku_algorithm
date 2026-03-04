#include "BitBoard.h"

BitBoard::BitBoard()
{
	this->bit_board[0] = 0;
	this->bit_board[1] = 0;
	this->bit_board[2] = 0;
}

BitBoard::BitBoard(const unsigned int a, const unsigned int b, const unsigned int c)
{
	this->bit_board[0] = a;
	this->bit_board[1] = b;
	this->bit_board[2] = c;
}

bool BitBoard::is_valid(const Coordinate xy) const
{
	if ((this->bit_board[xy.get_bitboard_index()] & xy.get_bitboard_y_mask()) != 0) return false;  // y座標固定

	if ((this->bit_board[xy.get_bitboard_index()] & xy.get_bitboard_group_mask()) != 0) return false;  // group固定

	// 以下x座標固定
	const unsigned int mask_x = xy.get_bitboard_x_mask();
	if ((this->bit_board[0] & mask_x) != 0) return false;
	if ((this->bit_board[1] & mask_x) != 0) return false;
	if ((this->bit_board[2] & mask_x) != 0) return false;

	return true;
}

void BitBoard::set(const Coordinate xy)
{
	this->bit_board[xy.get_bitboard_index()] |= xy.get_bitboard_spesific_mask();
}

void BitBoard::erase(const Coordinate xy)
{
	this->bit_board[xy.get_bitboard_index()] &= ~xy.get_bitboard_spesific_mask();
}

bool BitBoard::does_exist(const Coordinate xy) const
{
	return (this->bit_board[xy.get_bitboard_index()] & xy.get_bitboard_spesific_mask()) != 0;
}

BitBoard BitBoard::copy() const
{
	return BitBoard(this->bit_board[0], this->bit_board[1], this->bit_board[2]);
}

bool operator==(const BitBoard& a, const BitBoard& b)
{
	if (a.bit_board[0] != b.bit_board[0]) return false;
	if (a.bit_board[1] != b.bit_board[1]) return false;
	if (a.bit_board[2] != b.bit_board[2]) return false;
	return true;
}

bool operator!=(const BitBoard& a, const BitBoard& b)
{
	return !(a == b);
}
