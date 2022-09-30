#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <array>

class Piece
{
public:

	int m_value;
	bool m_player_1;
	std::array<int, 2> m_position;

	Piece(int value, bool player_1, int x, int y);

	virtual void move();
	virtual std::vector<int> get_possible_squares();

};

#endif