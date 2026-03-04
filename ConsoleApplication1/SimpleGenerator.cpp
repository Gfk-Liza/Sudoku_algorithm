#include "SimpleGenerator.h"

bool SimpleGenerator::is_valid()
{
    this->solver.set(this->board);
    this->solver.solve();
    Board tmp_board = this->solver.get();
    this->solver.set(this->board);
    this->solver.reverse_solve();
    Board tmp2_board = this->solver.get();
    return tmp_board == tmp2_board;
}

bool SimpleGenerator::erase(const unsigned int index)
{
    const Board saved_board = this->board.copy();

    for (unsigned int i = 0; i < index; ++i) {
        this->board.erase(this->delete_order[i]);
    }
    const bool result = this->is_valid();
    if (result) return true;
    this->board = saved_board;
    return false;
}

void SimpleGenerator::base_generator()
{
    this->base_generator(Coordinate());
}

bool SimpleGenerator::base_generator(Coordinate xy)
{
    if (!xy.is_valid()) return true;
    if (!this->board.is_empty(xy)) {
        xy.increase();
        return this->base_generator(xy);
    }
    Coordinate next_xy = xy;
    next_xy.increase();
    std::array<int, 9> shuffled_numbers = this->shuffler();
    for (unsigned int i = 0; i < BOARD_SIZE; ++i) {
        if (!this->board.is_valid(xy, shuffled_numbers[i])) continue;
        this->board.set(xy, shuffled_numbers[i]);
        if (this->base_generator(next_xy)) return true;
        this->board.erase(xy, shuffled_numbers[i]);
    }
    return false;
}

void SimpleGenerator::init_delete_order()
{
    std::shuffle(delete_order.begin(), delete_order.end(), this->mt);
}

SimpleGenerator::SimpleGenerator()
{
    this->board = Board();
    this->solver = SimpleSolver();
    Coordinate tmp;
    for (unsigned int i = 0; i < CELL_NUMBER; ++i) {
        this->delete_order[i] = tmp;
        tmp.increase();
    }
}

unsigned int SimpleGenerator::generate()
{
    return this->generate(BLANK_MAX_NUMBER);
}

unsigned int SimpleGenerator::generate(const unsigned int blank_max)
{
    this->init_random_gen();
    this->init_delete_order();
    this->base_generator();

    unsigned int left = 2;
    unsigned int right = std::min(blank_max, BLANK_MAX_NUMBER);
    unsigned int mid;
    while (left + 1 != right) {
        mid = (left + right) >> 1;
        const bool result = this->erase(mid);
        if (result) left = mid;
        else right = mid;
    }
    return left;
}

Board SimpleGenerator::get() const
{
    return this->board.copy();
}
