#include <map>

const int A1 = 0;
const int B1 = 1;
const int C1 = 2;
const int D1 = 3;
const int E1 = 4;
const int F1 = 5;
const int G1 = 6;
const int H1 = 7;
const int A2 = 8;
const int B2 = 9;
const int C2 = 10;
const int D2 = 11;
const int E2 = 12;
const int F2 = 13;
const int G2 = 14;
const int H2 = 15;
const int A3 = 16;
const int B3 = 17;
const int C3 = 18;
const int D3 = 19;
const int E3 = 20;
const int F3 = 21;
const int G3 = 22;
const int H3 = 23;
const int A4 = 24;
const int B4 = 25;
const int C4 = 26;
const int D4 = 27;
const int E4 = 28;
const int F4 = 29;
const int G4 = 30;
const int H4 = 31;
const int A5 = 32;
const int B5 = 33;
const int C5 = 34;
const int D5 = 35;
const int E5 = 36;
const int F5 = 37;
const int G5 = 38;
const int H5 = 39;
const int A6 = 40;
const int B6 = 41;
const int C6 = 42;
const int D6 = 43;
const int E6 = 44;
const int F6 = 45;
const int G6 = 46;
const int H6 = 47;
const int A7 = 48;
const int B7 = 49;
const int C7 = 50;
const int D7 = 51;
const int E7 = 52;
const int F7 = 53;
const int G7 = 54;
const int H7 = 55;
const int A8 = 56;
const int B8 = 57;
const int C8 = 58;
const int D8 = 59;
const int E8 = 60;
const int F8 = 61;
const int G8 = 62;
const int H8 = 63;

const int BB_A1 = 1 << A1;
const int BB_B1 = 1 << B1;
const int BB_C1 = 1 << C1;
const int BB_D1 = 1 << D1;
const int BB_E1 = 1 << E1;
const int BB_F1 = 1 << F1;
const int BB_G1 = 1 << G1;
const int BB_H1 = 1 << H1;
const int BB_A2 = 1 << A2;
const int BB_B2 = 1 << B2;
const int BB_C2 = 1 << C2;
const int BB_D2 = 1 << D2;
const int BB_E2 = 1 << E2;
const int BB_F2 = 1 << F2;
const int BB_G2 = 1 << G2;
const int BB_H2 = 1 << H2;
const int BB_A3 = 1 << A3;
const int BB_B3 = 1 << B3;
const int BB_C3 = 1 << C3;
const int BB_D3 = 1 << D3;
const int BB_E3 = 1 << E3;
const int BB_F3 = 1 << F3;
const int BB_G3 = 1 << G3;
const int BB_H3 = 1 << H3;
const int BB_A4 = 1 << A4;
const int BB_B4 = 1 << B4;
const int BB_C4 = 1 << C4;
const int BB_D4 = 1 << D4;
const int BB_E4 = 1 << E4;
const int BB_F4 = 1 << F4;
const int BB_G4 = 1 << G4;
const int BB_H4 = 1 << H4;
const int BB_A5 = 1 << A5;
const int BB_B5 = 1 << B5;
const int BB_C5 = 1 << C5;
const int BB_D5 = 1 << D5;
const int BB_E5 = 1 << E5;
const int BB_F5 = 1 << F5;
const int BB_G5 = 1 << G5;
const int BB_H5 = 1 << H5;
const int BB_A6 = 1 << A6;
const int BB_B6 = 1 << B6;
const int BB_C6 = 1 << C6;
const int BB_D6 = 1 << D6;
const int BB_E6 = 1 << E6;
const int BB_F6 = 1 << F6;
const int BB_G6 = 1 << G6;
const int BB_H6 = 1 << H6;
const int BB_A7 = 1 << A7;
const int BB_B7 = 1 << B7;
const int BB_C7 = 1 << C7;
const int BB_D7 = 1 << D7;
const int BB_E7 = 1 << E7;
const int BB_F7 = 1 << F7;
const int BB_G7 = 1 << G7;
const int BB_H7 = 1 << H7;
const int BB_A8 = 1 << A8;
const int BB_B8 = 1 << B8;
const int BB_C8 = 1 << C8;
const int BB_D8 = 1 << D8;
const int BB_E8 = 1 << E8;
const int BB_F8 = 1 << F8;
const int BB_G8 = 1 << G8;
const int BB_H8 = 1 << H8;

std::map<int, int> BB_SQUARES = {
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