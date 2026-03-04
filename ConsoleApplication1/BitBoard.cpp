#include "BitBoard.h"

BitBoard::BitBoard()
{
	for (unsigned int i = 0; i < BOARD_SIZE; ++i) {
		for (unsigned int j = 0; j < BOARD_SIZE; ++j) {
			this->bitboard[i][j] = false;
		}
	}
}
