#include <vector>
#include <bit>

#include "Square.h"

class Bitboard
{
private:
    int bitboard;

    Bitboard _sliding_attacks(Square square, Bitboard occupied, std::vector<int> deltas);
    Bitboard _step_attacks(Square square, Bitboard occupied, std::vector<int> deltas);

    static const int BB_ALL = 0xffffffffffffffff;
    static const int BB_EMPTY = 0x0;

    static const int BB_LIGHT_SQUARES = 0x55aa55aa55aa55aa;
    static const int BB_DARK_SQUARES = 0xaa55aa55aa55aa55;

    static const int BB_CORNERS = BB_A1 | BB_H1 | BB_A8 | BB_H8;
    static const int BB_CENTER = BB_D4 | BB_E4 | BB_D5 | BB_E5;

    static const int BB_FILE_A = 0x0101010101010101 << 0;
    static const int BB_FILE_B = 0x0101010101010101 << 1;
    static const int BB_FILE_C = 0x0101010101010101 << 2;
    static const int BB_FILE_D = 0x0101010101010101 << 3;
    static const int BB_FILE_E = 0x0101010101010101 << 4;
    static const int BB_FILE_F = 0x0101010101010101 << 5;
    static const int BB_FILE_G = 0x0101010101010101 << 6;
    static const int BB_FILE_H = 0x0101010101010101 << 7;

    static const int BB_RANK_1 = 0xff << 0;
    static const int BB_RANK_2 = 0xff << 8;
    static const int BB_RANK_3 = 0xff << 16;
    static const int BB_RANK_4 = 0xff << 24;
    static const int BB_RANK_5 = 0xff << 32;
    static const int BB_RANK_6 = 0xff << 40;
    static const int BB_RANK_7 = 0xff << 48;
    static const int BB_RANK_8 = 0xff << 52;

    static const int BB_BACKRANKS = BB_RANK_1 | BB_RANK_8;

    static const std::vector<int> KNIGHT_DELTAS = {17, 15, 10, 6, -17, -15, -10, -6};
    static const std::vector<int> KING_DELTAS = {9, 8, 7, 1, -9, -8, -7, -1};
    static const std::vector<int> PAWN_DELTAS_1 = {-7, -9};
    static const std::vector<int> PAWN_DELTAS_2 = {7, 9};

    static std::vector<BitBoard> build_attacks(std::vector<int> deltas)
    {
        std::vector<Bitboard> ret;

        for (auto sq : SQUARES)
        {
             ret.push_back(_step_attacks(sq, deltas);
        }

        return ret;
    }

    static std::vector<Bitboard> BB_KNIGHT_ATTACKS()
    {
        return Bitboard.build_attacks(KNIGHT_DELTAS);
    }
    static std::vector<Bitboard> BB_KING_ATTACKS()
    {
        return Bitboard.build_attacks(KING_DELTAS);
    }
    static std::vector<Bitboard> BB_PAWN_ATTACKS()
    {
        return Bitboard.build_attacks(PAWN_DELTAS);
    }

public:
    Bitboard(const int bitboard_ = 0) : bitboard(bitboard_)
    {
    }
    Bitboard flip_vertical();

    Bitboard flip_horizontal();

    Bitboard flip_diagonal();

    Bitboard flip_anti_diagonal();

    /*
     y: Vertical shift, positive = up
     x: Horizontal shift, positive = right
    */
    Bitboard shift(int x, int y);

    int lsb()
    {
        return std::bit_width(bitboard & -bb) - 1;
    }

    int msb()
    {
        return std::bit_width(bitboard) - 1;
    }

    std::vector<Square> scan_forward()
    {
        std::vector<Square> ret;
        int bb = bitboard;
        while (bb)
        {
            int r = bb & -bb;
            ret.push_back(Square(std::bit_width(r) - 1));
            bb ^= r;
        }
        return ret;
    }

    std::vector<Square> scan_reversed()
    {
        std::vector<Square> ret;
        int bb = bitboard;
        while (bb)
        {
            int r = std::bit_width(bitboard) - 1;
            ret.push_back(Square(r));
            bb ^= BB_SQUARES[r];
        }
        return ret;
    }
};