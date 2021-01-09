#include <string>
#include <tuple>
#include "Bitboard.h"
#include "Piece.h"

const std::string STARTING_BOARD_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";

class BaseBoard
{
public:
    std::tuple<Bitboard, Bitboard> occupied_co;

    BaseBoard(std::string board_fen = STARTING_BOARD_FEN)
    {
        std::get<0>(occupied_co) = BitboardTools::BB_EMPTY;
        std::get<1>(occupied_co) = BitboardTools::BB_EMPTY;
    }
};