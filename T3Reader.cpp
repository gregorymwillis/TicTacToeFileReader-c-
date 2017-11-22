/*************************************************************************************
** Name: Greg Willis
** Date: 11/19/2017
** Description: (T3Reader.cpp)
************************************************************************************/
#include "T3Reader.hpp"
#include "Board.hpp"
#include <string>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

// Default constructor
T3Reader::T3Reader() {
	// Create game board object
	gB = Board();
	// Set firstMove to x
	firstMove = 'x';
}

// Constructor with player 'x' or 'o' as the first move
T3Reader::T3Reader(char fM) {
	// Create game board object
	gB = Board();
	// Set firstMove to passed-in char
	firstMove = fM;
}

// This function opens the file of moves, it reads a move and then makes that move.
// It alternates players depending on which constructor was used. This function
// will return true if 'x' won, 'o' won, or there was a draw AND there are no more
// moves in the file. If there are, it returns false. If a move is attempted on an
// occupied square, it returns false.
bool T3Reader::readGameFile(string fileName) {
	// File object to read from
	ifstream inputFile;
	// row and column read from file
	int row, col;
	// Game state object
	GmState status = UNFINISHED;
	// Open the file to read from
	inputFile.open(fileName.c_str());

	if(inputFile) { // If able to open the file
		// While the game is unfinished and not to the end of the file,
		// keep looping

		while(inputFile >> row) { // Keep looping while able to take int from file

			// Read move
			inputFile >> col;

			// if the game has already finished, but we read another row for moves
			// then return false, there should not be any more moves.
			if(status != UNFINISHED) {
				return false;
			} else if(gB.makeMove(row, col, firstMove)) { // else if a move can be made

				// Get game state
				status = gB.gameState();

				changePlayer(firstMove);
				// gB.print();
			} else {
					inputFile.close();
					return false;
			}
		}

		// success: we either finished with X_WON, O_WON or DRAW:
		inputFile.close();
		return true;

	} else { // File was unable to open
		return false;
	}

	// When game has completed with a winner and no more moves return true
	return true;
}

void T3Reader::changePlayer(char &fM) {
	if(fM == 'x') {
		fM = 'o';
	}
	else {
		fM = 'x';
	}

}
