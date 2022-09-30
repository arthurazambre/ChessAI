#include "Piece.hpp"

Piece::Piece(int value, bool player_1, int x, int y): m_value(value), m_player_1(player_1), m_position({x, y}) {}