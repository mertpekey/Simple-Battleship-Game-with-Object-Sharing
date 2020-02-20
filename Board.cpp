
#include "Board.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Mert Pekey 23646

Board::Board()
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			theBoard[i][j]=0;
}

void Board::displayBoard() //Print the board on the screen
{
	cout<<"Board:"<<endl;
	cout<<setw(9)<<"P1"<<setw(7)<<"|"<<setw(9)<<"P2"<<endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout<<setw(4)<<theBoard[i][j];
			if (j==2)
			{
				cout<<setw(4)<<"|";
			}
		}
		cout<<endl;
	}
	cout<<endl;

}

bool Board::putShip(int playerid, int shipid, int rowStart, int colStart, int rowEnd, int colEnd)
{
	if(shipid==1 || shipid==2) //check if the ship id is legit
	{
		if (rowStart==rowEnd) //If ship is vertical
		{
			if (playerid==1)
			{
				if(rowStart<0 || rowStart>5 || colEnd<0 || colStart<0 || colEnd>2 || colStart>2)
					return false;
			}
			else if (playerid==2)
			{
				if(rowStart<0 || rowStart>5 || colEnd<3 || colStart<3 || colEnd>5 || colStart>5)
					return false;
			}

			if (colEnd>colStart)	//ships can look to both sides. Check which way they look
			{
				if (shipid==1)
				{
					if(colEnd-colStart!=1)
						return false;
				}
				else if (shipid==2)
				{
					if(colEnd-colStart!=2)
						return false;
				}

				for (int i = colStart; i <= colEnd; i++)
				{
					if(theBoard[rowStart][i]!=0)
						return false;
				}

				for (int i = colStart; i <= colEnd; i++)
					theBoard[rowStart][i]=1;
			}
			else if(colEnd<colStart)
			{
				if (shipid==1)
				{
					if(colEnd-colStart!=-1)
						return false;
				}
				else if (shipid==2)
				{
					if(colEnd-colStart!=-2)
						return false;
				}

				for (int i = colEnd; i >= colStart; i--)
				{
					if(theBoard[rowStart][i]!=0)
						return false;
				}

				for (int i = colEnd; i >= colStart; i--)
					theBoard[rowStart][i]=1;
			}

		}
		else if (colStart==colEnd)	//If ships are horizontal
		{
			if (playerid==1)
			{
				if(rowStart<0 || rowStart>5 || colEnd<0 || colStart<0 || colEnd>2 || colStart>2)
					return false;
			}
			else if (playerid==2)
			{
				if(rowStart<0 || rowStart>5 || colEnd<3 || colStart<3 || colEnd>5 || colStart>5)
					return false;
			}



			if (rowEnd>rowStart)
			{
				if (shipid==1)
				{
					if(rowEnd-rowStart!=1)
						return false;
				}
				else if (shipid==2)
				{
					if(rowEnd-rowStart!=2)
						return false;
				}

				for (int i = rowStart; i <= rowEnd; i++)
				{
					if(theBoard[i][colStart]!=0)
						return false;
				}

				for (int i = rowStart; i <= rowEnd; i++)
					theBoard[i][colStart]=1;
			}
			else if(rowEnd<rowStart)
			{
				if (shipid==1)
				{
					if(rowEnd-rowStart!=-1)
						return false;
				}
				else if (shipid==2)
				{
					if(rowEnd-rowStart!=-2)
						return false;
				}

				for (int i = rowEnd; i <= rowStart; i--)
				{
					if(theBoard[i][colStart]!=0)
						return false;
				}

				for (int i = rowEnd; i <= rowStart; i--)
					theBoard[i][colStart]=1;
			}

		}
		else
			return false;
	}
	else
		return false;

	return true;

}

bool Board::makeAHit(int row, int column) //If we hit the ship, make that part -1
{
	if (theBoard[row][column]==0)
	{
		return false;
	}
	else if (theBoard[row][column]==1)
	{
		theBoard[row][column]=-1;
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::CheckIfPlayerWon(int playerid) //If there is no part that include 1 ot one player's side, other player wins the game
{
	if (playerid==1)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (theBoard[i][j]==1)
				{
					return false;
				}
			}
		}
		return true;
	}
	else if (playerid==2)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (theBoard[i][j]==1)
				{
					return false;
				}
			}
		}
		return true;
	}
}