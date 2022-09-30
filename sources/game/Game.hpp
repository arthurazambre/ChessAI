#ifndef GAME_HPP
#define GAME_HPP

#include <array>

class Game
{
public:

	static std::array<int, 2> players;

	static void show_board();

	static void play();
};

#endif