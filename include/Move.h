#include "Square.h"
#include "Piece.h"

class Move
{
    Square from_square;
    Square to_square;

    PieceType promotion = NONE;
    PieceType drop = NONE;

    Move() : from_square(0), to_square(0) {}
};