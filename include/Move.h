#include "Square.h"
#include "Piece.h"

class Move
{
public:
    Square from_square;
    Square to_square;

    PieceType promotion;
    PieceType drop;

    Move(Square _from_square, Square _to_square, PieceType _promotion = PieceType::NONE, PieceType _drop = PieceType::NONE)
        : from_square(_from_square), to_square(_to_square), promotion(_promotion), drop(_drop)
    {
    }
};

namespace MoveTools
{
    Move from_uci(std::string uci)
    {
        if (uci == "0000")
        {
            return null();
        }
        else if (uci.length() == 4 && uci[1] == '@')
        {
        }
        else if (4 <= uci.length() <= 5)
        {
            Square from_square = SquareTools::parse(uci.substr(0, 2));
            Square to_square = SquareTools::parse(uci.substr(2, 2));
            PieceType promotion = uci.length() == 5 ? PieceTypeTools::parse(uci[4]) : PieceType::NONE;
            return Move(from_square, to_square, promotion);
        }
        throw "error";
    }

    Move null()
    {
        return Move(0, 0);
    }
} // namespace MoveTools