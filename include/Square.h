#include <string>
#include <vector>

#include "Squares.h"

class Square
{
private:
    int square;

    const std::vector<char> FILE_NAMES = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    const std::vector<char> RANK_NAMES = {'1', '2', '3', '4', '5', '6', '7', '8'};

public:
    Square(std::string name_)
    {
    }

    Square(int square_) : square(square_) {}

    Square(int file_, int rank_) : square(rank_ * 8 + file_) {}

    int file()
    {
        return square & 7;
    }

    int rank()
    {
        return square >> 3;
    }

    int distance(Square b)
    {
        return std::max(std::abs(this.file() - b.file()), std::abs(this.rank() - b.rank()));
    }
};