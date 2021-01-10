#pragma once

#include "Bitboard.h"

#include "Squares.h"

const Bitboard BB_A1 = (uint64_t)1 << A1;
const Bitboard BB_B1 = (uint64_t)1 << B1;
const Bitboard BB_C1 = (uint64_t)1 << C1;
const Bitboard BB_D1 = (uint64_t)1 << D1;
const Bitboard BB_E1 = (uint64_t)1 << E1;
const Bitboard BB_F1 = (uint64_t)1 << F1;
const Bitboard BB_G1 = (uint64_t)1 << G1;
const Bitboard BB_H1 = (uint64_t)1 << H1;
const Bitboard BB_A2 = (uint64_t)1 << A2;
const Bitboard BB_B2 = (uint64_t)1 << B2;
const Bitboard BB_C2 = (uint64_t)1 << C2;
const Bitboard BB_D2 = (uint64_t)1 << D2;
const Bitboard BB_E2 = (uint64_t)1 << E2;
const Bitboard BB_F2 = (uint64_t)1 << F2;
const Bitboard BB_G2 = (uint64_t)1 << G2;
const Bitboard BB_H2 = (uint64_t)1 << H2;
const Bitboard BB_A3 = (uint64_t)1 << A3;
const Bitboard BB_B3 = (uint64_t)1 << B3;
const Bitboard BB_C3 = (uint64_t)1 << C3;
const Bitboard BB_D3 = (uint64_t)1 << D3;
const Bitboard BB_E3 = (uint64_t)1 << E3;
const Bitboard BB_F3 = (uint64_t)1 << F3;
const Bitboard BB_G3 = (uint64_t)1 << G3;
const Bitboard BB_H3 = (uint64_t)1 << H3;
const Bitboard BB_A4 = (uint64_t)1 << A4;
const Bitboard BB_B4 = (uint64_t)1 << B4;
const Bitboard BB_C4 = (uint64_t)1 << C4;
const Bitboard BB_D4 = (uint64_t)1 << D4;
const Bitboard BB_E4 = (uint64_t)1 << E4;
const Bitboard BB_F4 = (uint64_t)1 << F4;
const Bitboard BB_G4 = (uint64_t)1 << G4;
const Bitboard BB_H4 = (uint64_t)1 << H4;
const Bitboard BB_A5 = (uint64_t)1 << A5;
const Bitboard BB_B5 = (uint64_t)1 << B5;
const Bitboard BB_C5 = (uint64_t)1 << C5;
const Bitboard BB_D5 = (uint64_t)1 << D5;
const Bitboard BB_E5 = (uint64_t)1 << E5;
const Bitboard BB_F5 = (uint64_t)1 << F5;
const Bitboard BB_G5 = (uint64_t)1 << G5;
const Bitboard BB_H5 = (uint64_t)1 << H5;
const Bitboard BB_A6 = (uint64_t)1 << A6;
const Bitboard BB_B6 = (uint64_t)1 << B6;
const Bitboard BB_C6 = (uint64_t)1 << C6;
const Bitboard BB_D6 = (uint64_t)1 << D6;
const Bitboard BB_E6 = (uint64_t)1 << E6;
const Bitboard BB_F6 = (uint64_t)1 << F6;
const Bitboard BB_G6 = (uint64_t)1 << G6;
const Bitboard BB_H6 = (uint64_t)1 << H6;
const Bitboard BB_A7 = (uint64_t)1 << A7;
const Bitboard BB_B7 = (uint64_t)1 << B7;
const Bitboard BB_C7 = (uint64_t)1 << C7;
const Bitboard BB_D7 = (uint64_t)1 << D7;
const Bitboard BB_E7 = (uint64_t)1 << E7;
const Bitboard BB_F7 = (uint64_t)1 << F7;
const Bitboard BB_G7 = (uint64_t)1 << G7;
const Bitboard BB_H7 = (uint64_t)1 << H7;
const Bitboard BB_A8 = (uint64_t)1 << A8;
const Bitboard BB_B8 = (uint64_t)1 << B8;
const Bitboard BB_C8 = (uint64_t)1 << C8;
const Bitboard BB_D8 = (uint64_t)1 << D8;
const Bitboard BB_E8 = (uint64_t)1 << E8;
const Bitboard BB_F8 = (uint64_t)1 << F8;
const Bitboard BB_G8 = (uint64_t)1 << G8;
const Bitboard BB_H8 = (uint64_t)1 << H8;

std::map<int, Bitboard> BB_SQUARES = {
    {A1, BB_A1},
    {B1, BB_B1},
    {C1, BB_C1},
    {D1, BB_D1},
    {E1, BB_E1},
    {F1, BB_F1},
    {G1, BB_G1},
    {H1, BB_H1},
    {A2, BB_A2},
    {B2, BB_B2},
    {C2, BB_C2},
    {D2, BB_D2},
    {E2, BB_E2},
    {F2, BB_F2},
    {G2, BB_G2},
    {H2, BB_H2},
    {A3, BB_A3},
    {B3, BB_B3},
    {C3, BB_C3},
    {D3, BB_D3},
    {E3, BB_E3},
    {F3, BB_F3},
    {G3, BB_G3},
    {H3, BB_H3},
    {A4, BB_A4},
    {B4, BB_B4},
    {C4, BB_C4},
    {D4, BB_D4},
    {E4, BB_E4},
    {F4, BB_F4},
    {G4, BB_G4},
    {H4, BB_H4},
    {A5, BB_A5},
    {B5, BB_B5},
    {C5, BB_C5},
    {D5, BB_D5},
    {E5, BB_E5},
    {F5, BB_F5},
    {G5, BB_G5},
    {H5, BB_H5},
    {A6, BB_A6},
    {B6, BB_B6},
    {C6, BB_C6},
    {D6, BB_D6},
    {E6, BB_E6},
    {F6, BB_F6},
    {G6, BB_G6},
    {H6, BB_H6},
    {A7, BB_A7},
    {B7, BB_B7},
    {C7, BB_C7},
    {D7, BB_D7},
    {E7, BB_E7},
    {F7, BB_F7},
    {G7, BB_G7},
    {H7, BB_H7},
    {A8, BB_A8},
    {B8, BB_B8},
    {C8, BB_C8},
    {D8, BB_D8},
    {E8, BB_E8},
    {F8, BB_F8},
    {G8, BB_G8},
    {H8, BB_H8}};