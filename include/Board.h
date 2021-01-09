#include "BaseBoard.h"
#include "Move.h"

#include "LegalMoveGenerator.h"

class Board : public BaseBoard
{
public:
    Color turn;
    Bitboard castling_rights;
    int fullmove_number;
    int halfmove_clock;
    Bitboard promoted;
    std::vector<Move> move_stack;

    Board(std::string fen) : BaseBoard()
    {
    }

    std::vector<Move> legal_moves()
    {
        return LegalMoveGenerator(*this).legal_moves();
    }
};