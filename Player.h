#include <iostream>
#include "Board.h"

//Mert Pekey 23646

class Player{

public:

	Player();
	Player::Player(Board &myboard,int playerid)
		: board(myboard), id(playerid)
		{}
	bool guess(int row, int column);
	bool wins();

private:

	int id;
	Board &board;
};