#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <string>

#include "Squares.h"

typedef uint64_t Square;

namespace SquareTools
{
    const std::vector<char> FILE_NAMES = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    const std::vector<char> RANK_NAMES = {'1', '2', '3', '4', '5', '6', '7', '8'};
    Square square(int file_idx, int rank_idx)
    {
        return rank_idx * 8 + file_idx;
    }

    Square parse(std::string name_)
    {
        auto file = std::find(FILE_NAMES.begin(), FILE_NAMES.end(), name_[0]);
        auto rank = std::find(RANK_NAMES.begin(), RANK_NAMES.end(), name_[1]);

        if (file != FILE_NAMES.end() && rank != RANK_NAMES.end())
        {
            int file_idx = std::distance(file, FILE_NAMES.end());
            int rank_idx = std::distance(rank, FILE_NAMES.end());

            return square(file_idx, rank_idx);
        }

        throw std::exception();
    }

    std::string name(Square square)
    {
        return {FILE_NAMES[square / 8], RANK_NAMES[square % 8]};
    }

    int file(Square square)
    {
        return square & 7;
    }

    int rank(Square square)
    {
        return square >> 3;
    }

    int distance(Square a, Square b)
    {
        return std::max(std::abs(file(a) - file(b)), std::abs(rank(a) - rank(b)));
    }

}; // namespace SquareTools
