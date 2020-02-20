#include <iostream>
#include <iomanip>

//Mert Pekey 23646

class Board{

public:

	Board();
	void displayBoard();
	bool putShip(int playerid, int shipid, int rowStart, int colStart, int rowEnd, int colEnd);
	bool makeAHit(int row, int column);
	bool CheckIfPlayerWon(int playerid);

private:

	int theBoard[6][6];
};