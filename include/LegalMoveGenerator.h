#pragma once

#include "Board.h"

class LegalMoveGenerator
{
    Board &board;

public:
    LegalMoveGenerator(Board &_board) : board(_board)
    {
    }

    std::vector<Move> generate_legal_moves(Bitboard from_mask, Bitboard to_mask)
    {
        std::vector<Move> moves;
        if (board.is_variant_end())
        {
            return moves;
        }

        Bitboard king_mask = board.kings & board.occupied_co[board.turn];

        if (king_mask)
        {
            Bitboard king = BitboardTools::msb(king_mask);
            Bitboard blockers = board._slider_blockers(king);
            Bitboard checkers = board.attackers_mask(not self.turn, king);
            if (checkers)
            {
                for (Move move : board._generate_evasions(king, checkers, from_mask, to_mask))
                {
                    if (board._is_safe(king, blockers, move))
                    {
                        moves.push_back(move);
                    }
                }
            }
            else
            {
                for (Move move : generate_pseudo_legal_moves(from_mask, to_mask))
                {
                    if (board._is_safe(king, blockers, move))
                    {
                        moves.push_back(move);
                    }
                }
            }
        }
        else
        {
            return generate_pseudo_legal_moves(from_mask, to_mask)
        }
    }

    std::vector<Move> legal_moves()
    {
        return generate_legal_moves();
    }
};