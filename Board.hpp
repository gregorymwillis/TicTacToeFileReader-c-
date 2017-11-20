/**********************************************************************************
** Name: Greg Willis
** Date: 11/18/2017
** Description: (Board.hpp) This class represents a tic-tac-toe board. It has a 
**		3X3 array to store players' moves. This is the header file of the
**		class.
**********************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

enum GmState {X_WON, O_WON, DRAW, UNFINISHED};

class Board {

	private:
		// Array holds all players' moves
		char gameBoardArray[3][3];
		// Checks rows for three in a row match
		bool checkRows(char);
		// Check columns for three in a row match
		bool checkCols(char);
		// Check diagonals for three in a row match
		bool checkDiag(char);
		// Check to see if game is unfinished
		bool hasEmptySquare();

	public:
		// Default constructor
		Board();
		// Stores a player's move
		bool makeMove(int, int, char);
		// Returns the state of the game
		GmState gameState();
		// Prints the gameBoardArray
		void print();

};
#endif
