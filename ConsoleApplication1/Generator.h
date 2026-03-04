#pragma once

#include <random>
#include <algorithm>
#include <array>

class Generator
{
protected:
    std::mt19937 mt;
    std::array<int, 9> shuffler();
    void init_random_gen();

public:
    Generator()
        : mt(std::random_device{}())
    {
    };

};
