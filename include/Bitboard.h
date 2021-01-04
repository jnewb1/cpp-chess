#pragma once

#include <cstdint>

#include <vector>
#include <limits>

typedef uint64_t Bitboard;

#include "Square.h"

// https://en.cppreference.com/w/cpp/numeric/bit_width
template <class T>
int countl_zero(T x)
{
    for (int i = 0; i < std::numeric_limits<T>::digits; i++)
    {
        if (1 << (x - 1))
        {
            return i;
        }
        x << 1;
    }

    return 0;
}

template <class T>
int bit_width(T x)
{
    return std::numeric_limits<T>::digits - countl_zero(x);
}

class BitboardTools
{
private:
    static Bitboard _sliding_attacks(Square square, Bitboard occupied, std::vector<int64_t> deltas);
    static Bitboard _step_attacks(Square square, std::vector<int64_t> deltas);

    static std::vector<Bitboard> build_attacks(std::vector<int64_t> deltas)
    {
        std::vector<Bitboard> ret;

        for (auto sq : SQUARES)
        {
            ret.push_back(_step_attacks(sq, deltas));
        }

        return ret;
    }

public:
    static const Bitboard BB_ALL = 0xffffffffffffffff;
    static const Bitboard BB_EMPTY = 0x0;

    static const Bitboard BB_LIGHT_SQUARES = 0x55aa55aa55aa55aa;
    static const Bitboard BB_DARK_SQUARES = 0xaa55aa55aa55aa55;

    static const Bitboard BB_CORNERS = BB_A1 | BB_H1 | BB_A8 | BB_H8;
    static const Bitboard BB_CENTER = BB_D4 | BB_E4 | BB_D5 | BB_E5;

    static const Bitboard BB_FILE_A = (uint64_t)0x0101010101010101 << 0;
    static const Bitboard BB_FILE_B = (uint64_t)0x0101010101010101 << 1;
    static const Bitboard BB_FILE_C = (uint64_t)0x0101010101010101 << 2;
    static const Bitboard BB_FILE_D = (uint64_t)0x0101010101010101 << 3;
    static const Bitboard BB_FILE_E = (uint64_t)0x0101010101010101 << 4;
    static const Bitboard BB_FILE_F = (uint64_t)0x0101010101010101 << 5;
    static const Bitboard BB_FILE_G = (uint64_t)0x0101010101010101 << 6;
    static const Bitboard BB_FILE_H = (uint64_t)0x0101010101010101 << 7;

    static const Bitboard BB_RANK_1 = (uint64_t)0xff << 0;
    static const Bitboard BB_RANK_2 = (uint64_t)0xff << 8;
    static const Bitboard BB_RANK_3 = (uint64_t)0xff << 16;
    static const Bitboard BB_RANK_4 = (uint64_t)0xff << 24;
    static const Bitboard BB_RANK_5 = (uint64_t)0xff << 32;
    static const Bitboard BB_RANK_6 = (uint64_t)0xff << 40;
    static const Bitboard BB_RANK_7 = (uint64_t)0xff << 48;
    static const Bitboard BB_RANK_8 = (uint64_t)0xff << 52;

    static const std::vector<Bitboard> BB_FILES;
    static const std::vector<Bitboard> BB_RANKS;

    static const Bitboard BB_BACKRANKS = BB_RANK_1 | BB_RANK_8;

    static const std::vector<int64_t> KNIGHT_DELTAS;
    static const std::vector<int64_t> KING_DELTAS;
    static const std::vector<int64_t> PAWN_DELTAS_1;
    static const std::vector<int64_t> PAWN_DELTAS_2;

    static std::vector<Bitboard> BB_DIAG_MASKS;
    static std::vector<std::map<Bitboard, Bitboard>> BB_DIAG_ATTACKS;
    static std::vector<Bitboard> BB_FILE_MASKS;
    static std::vector<std::map<Bitboard, Bitboard>> BB_FILE_ATTACKS;
    static std::vector<Bitboard> BB_RANK_MASKS;
    static std::vector<std::map<Bitboard, Bitboard>> BB_RANK_ATTACKS;

    static std::vector<Bitboard> BB_KNIGHT_ATTACKS;
    static std::vector<Bitboard> BB_KING_ATTACKS;
    static std::vector<Bitboard> BB_PAWN_ATTACKS;

    static std::vector<std::vector<Bitboard>> BB_RAYS;

    BitboardTools()
    {
        BB_KNIGHT_ATTACKS = build_attacks(KNIGHT_DELTAS);

        BB_KING_ATTACKS = build_attacks(KING_DELTAS);

        BB_PAWN_ATTACKS = build_attacks(PAWN_DELTAS_1);

        std::vector<Bitboard> d = build_attacks(PAWN_DELTAS_2);
        BB_PAWN_ATTACKS.insert(BB_PAWN_ATTACKS.end(), d.begin(), d.end());

        auto diag_attack_table = _attack_table({-9, -7, 7, 9});
        BB_DIAG_MASKS = std::get<0>(diag_attack_table);
        BB_DIAG_ATTACKS = std::get<1>(diag_attack_table);

        auto file_attack_table = _attack_table({-8, 8});
        BB_FILE_MASKS = std::get<0>(file_attack_table);
        BB_FILE_ATTACKS = std::get<1>(file_attack_table);

        auto rank_attack_table = _attack_table({-1, 1});
        BB_RANK_MASKS = std::get<0>(rank_attack_table);
        BB_RANK_ATTACKS = std::get<1>(rank_attack_table);

        BB_RAYS = _rays();
    }
    static Bitboard flip_vertical(Bitboard bb);

    static Bitboard flip_horizontal(Bitboard bb);

    static Bitboard flip_diagonal(Bitboard bb);

    static Bitboard flip_anti_diagonal(Bitboard bb);

    /*
     y: Vertical shift, positive = up
     x: Horizontal shift, positive = right
    */
    static Bitboard shift(Bitboard bb, int x, int y);

    static int lsb(Bitboard bb)
    {
        return bit_width(bb & -bb) - 1;
    }

    static int msb(Bitboard bb)
    {
        return bit_width(bb) - 1;
    }

    std::vector<Square> scan_forward(Bitboard bb)
    {
        std::vector<Square> ret;
        while (bb)
        {
            int r = bb & -bb;
            ret.push_back(Square(bit_width(r) - 1));
            bb ^= r;
        }
        return ret;
    }

    std::vector<Square> scan_reversed(Bitboard bb)
    {
        std::vector<Square> ret;
        while (bb)
        {
            int r = bit_width(bb) - 1;
            ret.push_back(Square(r));
            bb ^= BB_SQUARES[r];
        }
        return ret;
    }

    Bitboard _edges(Square square)
    {
        return (((BB_RANK_1 | BB_RANK_8) & ~BB_RANKS[SquareTools::rank(square)]) |
                ((BB_FILE_A | BB_FILE_H) & ~BB_FILES[SquareTools::file(square)]));
    }

    struct _CarrierRipplerIterator
    {
    private:
        Bitboard subset;
        Bitboard mask;

    public:
        _CarrierRipplerIterator(Bitboard mask) : subset(BB_EMPTY), mask(mask)
        {
        }

        _CarrierRipplerIterator(Bitboard subset, Bitboard mask) : subset(subset), mask(mask)
        {
        }
        Bitboard operator*() const { return subset; }

        _CarrierRipplerIterator &operator++()
        {
            subset = (subset - mask) & mask;
            return *this;
        }

        _CarrierRipplerIterator operator++(int)
        {
            _CarrierRipplerIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const _CarrierRipplerIterator &a, const _CarrierRipplerIterator &b) { return a.subset == b.subset && a.mask == b.mask; };
        friend bool operator!=(const _CarrierRipplerIterator &a, const _CarrierRipplerIterator &b) { return a.subset != b.subset || a.mask != b.mask; };
        _CarrierRipplerIterator end() { return _CarrierRipplerIterator(BB_EMPTY, mask); }
    };

    typedef std::tuple<std::vector<Bitboard>, std::vector<std::map<Bitboard, Bitboard>>> _attack_table_tuple;

    _attack_table_tuple _attack_table(std::vector<int64_t> deltas)
    {
        std::vector<Bitboard> mask_table;
        std::vector<std::map<Bitboard, Bitboard>> attack_table;

        for (auto square : SQUARES)
        {
            std::map<Bitboard, Bitboard> attacks;

            auto mask = _sliding_attacks(square, 0, deltas) & ~_edges(square);
            for (auto subset = _CarrierRipplerIterator(mask); subset != _CarrierRipplerIterator(mask); subset++)
            {
                attacks[*subset] = _sliding_attacks(square, *subset, deltas);
            }

            attack_table.push_back(attacks);
            mask_table.push_back(mask);
        }
        return _attack_table_tuple(mask_table, attack_table);
    }

    std::vector<std::vector<Bitboard>> _rays()
    {
        std::vector<std::vector<Bitboard>> rays;

        for (auto kv_a : BB_SQUARES)
        {
            int a = kv_a.first;
            Bitboard bb_a = kv_a.second;
            std::vector<Bitboard> rays_row;
            for (auto kv_b : BB_SQUARES)
            {
                int b = kv_b.first;
                Bitboard bb_b = kv_b.second;

                if (BB_DIAG_ATTACKS[a][0] & bb_b)
                {

                    rays_row.push_back((BB_DIAG_ATTACKS[a][0] & BB_DIAG_ATTACKS[b][0]) | bb_a | bb_b);
                }
                else if (BB_RANK_ATTACKS[a][0] & bb_b)
                {

                    rays_row.push_back(BB_RANK_ATTACKS[a][0] | bb_a);
                }
                else if (BB_FILE_ATTACKS[a][0] & bb_b)
                {
                    rays_row.push_back(BB_FILE_ATTACKS[a][0] | bb_a);
                }
                else
                {
                    rays_row.push_back(BB_EMPTY);
                }
            }
            rays.push_back(rays_row);
        }
        return rays;
    }

    Bitboard ray(Square a, Square b)
    {
        return BB_RAYS[a][b];
    }

    Bitboard between(Square a, Square b)
    {
        Bitboard bb = BB_RAYS[a][b] & ((BB_ALL << a) ^ (BB_ALL << b));
        return bb & (bb - 1);
    }
};

const std::vector<int64_t>
    BitboardTools::KNIGHT_DELTAS = {17, 15, 10, 6, -17, -15, -10, -6};
const std::vector<int64_t> BitboardTools::KING_DELTAS = {9, 8, 7, 1, -9, -8, -7, -1};
const std::vector<int64_t> BitboardTools::PAWN_DELTAS_1 = {-7, -9};
const std::vector<int64_t> BitboardTools::PAWN_DELTAS_2 = {7, 9};

const std::vector<Bitboard> BitboardTools::BB_RANKS = {
    BitboardTools::BB_RANK_1,
    BitboardTools::BB_RANK_2,
    BitboardTools::BB_RANK_3,
    BitboardTools::BB_RANK_4,
    BitboardTools::BB_RANK_5,
    BitboardTools::BB_RANK_6,
    BitboardTools::BB_RANK_7,
    BitboardTools::BB_RANK_8};
const std::vector<Bitboard> BitboardTools::BB_FILES = {
    BitboardTools::BB_FILE_A,
    BitboardTools::BB_FILE_B,
    BitboardTools::BB_FILE_C,
    BitboardTools::BB_FILE_D,
    BitboardTools::BB_FILE_E,
    BitboardTools::BB_FILE_F,
    BitboardTools::BB_FILE_G,
    BitboardTools::BB_FILE_H};