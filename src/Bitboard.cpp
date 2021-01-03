#include "Bitboard.h"

Bitboard Bitboard::_sliding_attacks(Square square, Bitboard occupied, std::vector<int> deltas)
{
    Bitboard attacks = Bitboard(BB_EMPTY);

    for (auto delta : deltas)
    {
        Square sq = square;

        while (true)
        {
            sq += delta;
            if (!(0 <= sq < 64) || sq.distance(sq - delta) > 2)
            {
                break;
            }

            attacks |= BB_SQUARES[sq];

            if (occupied & BB_SQUARES[sq])
            {
                break;
            }
        }
    }

    return attacks;
}

Bitboard Bitboard::_step_attacks(Square square, Bitboard occupied, std::vector<int> deltas)
{
    return _sliding_attacks(square, Bitboard(BB_ALL), deltas);
}

Bitboard Bitboard::flip_vertical()
{
    int bb = bitboard;
    bb = ((bb >> 8) & 0x00ff00ff00ff00ff) | ((bb & 0x00ff00ff00ff00ff) << 8);
    bb = ((bb >> 16) & 0x0000ffff0000ffff) | ((bb & 0x0000ffff0000ffff) << 16);
    bb = (bb >> 32) | ((bb & 0x00000000ffffffff) << 32);
    return Bitboard(bb);
}

Bitboard Bitboard::flip_horizontal()
{
    int bb = bitboard;
    bb = ((bb >> 1) & 0x5555555555555555) | ((bb & 0x5555555555555555) << 1);
    bb = ((bb >> 2) & 0x3333333333333333) | ((bb & 0x3333333333333333) << 2);
    bb = ((bb >> 4) & 0x0f0f0f0f0f0f0f0f) | ((bb & 0x0f0f0f0f0f0f0f0f) << 4);
    return Bitboard(bb);
}
Bitboard Bitboard::flip_diagonal()
{
    int bb = bitboard;
    int t = (bb ^ (bb << 28)) & 0x0f0f0f0f00000000;
    bb = bb ^ (t ^ (t >> 28));
    t = (bb ^ (bitboard << 14)) & 0x3333000033330000;
    bb = bb ^ (t ^ (t >> 14));
    t = (bb ^ (bb << 7)) & 0x5500550055005500;
    bb = bb ^ (t ^ (t >> 7));
    return Bitboard(bb);
}
Bitboard Bitboard::flip_anti_diagonal()
{
    int bb = bitboard;

    int t = bb ^ (bb << 36);
    bb = bb ^ ((t ^ (bb >> 36)) & 0xf0f0f0f00f0f0f0f);
    t = (bb ^ (bb << 18)) & 0xcccc0000cccc0000;
    bb = bb ^ (t ^ (t >> 18));
    t = (bb ^ (bb << 9)) & 0xaa00aa00aa00aa00;
    bb = bb ^ (t ^ (t >> 9));
    return Bitboard(bb);
}

Bitboard Bitboard::shift(int x, int y)
{
    int bb = bitboard;

    if (y > 0)
    {
        bb = (bb << (8 * y)) & Bitboard::BB_ALL;
    }
    else
    {
        bb = (bb >> (8 * y));
    }

    return Bitboard(bb);
}
