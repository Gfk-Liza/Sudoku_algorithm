#pragma once
#include "Generator.h"
#include "Board.h"
#include "SimpleSolver.h"
#include <array>

class SimpleGenerator :
    public Generator
{
private:
    Board board;
    SimpleSolver solver;
    std::array<Coordinate, CELL_NUMBER> delete_order;
    bool is_valid();  // 解に一意性があるか調べる。
    bool erase(const unsigned int index); // this->delete_numberのindex-1までだけをeraseしたとき、返り値がtrueなら解に一意性がある、falseなら無い. falseのときは盤面を元に戻す.
    bool base_generator(Coordinate xy);  // 再帰用

    void init_delete_order();

public:
    SimpleGenerator();

    void base_generator();  // 外部呼び出し用

    unsigned int generate();  // 空白マスの個数を返す
    unsigned int generate(const unsigned int blank_max);  // 空白マスの個数の最大値を指定. 空白マスの個数を返す
    Board get() const;
};

