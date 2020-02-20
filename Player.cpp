#include "Player.h"
#include <iostream>

//Mert Pekey 23646

bool Player::guess(int row, int column)
{
	return board.makeAHit(row, column);	//use the board object on the player class to play the game on the same board
}

bool Player::wins()
{
	return board.CheckIfPlayerWon(this->id); //Look at the board to check if one of the player wins
}