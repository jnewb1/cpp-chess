#include <cstdint>
#include <string>

typedef bool Color;

enum PieceType : uint8_t
{
    NONE = 0,
    PAWN = 1,
    KNIGHT = 2,
    BISHOP = 3,
    ROOK = 4,
    QUEEN = 5,
    KING = 6
};

class Piece
{
private:
    PieceType piece_type;
    Color color;

    std::string symbol()
    {
        //
    }
};

namespace PieceTypeTools
{
    PieceType parse(char piece_char)
    {
        return PieceType::NONE;
    }
} // namespace PieceTypeTools