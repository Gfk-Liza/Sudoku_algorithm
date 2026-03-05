#pragma once
#include "Board.h"
#include "SimpleGenerator.h"
#include <iostream>
#include <chrono>

inline static const unsigned int LOOP_NUMBER = 10000;

int main() {
	std::chrono::system_clock::time_point begin;
	std::chrono::system_clock::time_point end;
	SimpleGenerator gen = SimpleGenerator();
	Board tmp_board;
	unsigned int max_holes = 0;
	begin = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < LOOP_NUMBER; ++i) {
		unsigned int tmp = gen.generate();
		if (max_holes < tmp) {
			max_holes = tmp;
			tmp_board = gen.get();
		}
	}
	end = std::chrono::system_clock::now();
	std::cout << max_holes << std::endl;
	tmp_board.print();

	long long t = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << "Elapsed(msec) = "
		<< t << std::endl;
	double t_1 = static_cast<double>(t) / static_cast<double>(LOOP_NUMBER);
	std::cout << t_1 << " (microsec/process)" << std::endl;
	return 0;
}

// normal: 849.8329 (microsec/process)
// bitboard: 635.9584 (microsec/process)

