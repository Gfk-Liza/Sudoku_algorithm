#pragma once
#include "Generator.h"

std::array<int, 9> Generator::shuffler()
{
    std::array<int, 9> tmp = { 1,2,3,4,5,6,7,8,9 };
    std::shuffle(tmp.begin(), tmp.end(), this->mt);
    return tmp;
}

void Generator::init_random_gen()
{
    this->mt = std::mt19937(std::random_device{}());
}
