#ifndef GRID_HPP
#define GRID_HPP

#include <array>
#include "Piece.hpp"

class Grid
{
public:

	static std::array<std::array<Piece, 8>, 8> starting_grid;
	std::array<std::array<Piece, 8>, 8> main_grid;

	Grid();

	void init_grid();
	void reset_grid();

};

#endif

