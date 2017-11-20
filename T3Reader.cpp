/*************************************************************************************
** Name: Greg Willis
** Date: 11/19/2017
** Description: (T3Reader.cpp)
************************************************************************************/
#include "T3Reader.hpp"
#include "Board.hpp"
#include <string>
#include <fstream>

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

	// Open the file to read from
	inputFile.open(fileName);

	if(inputFile) { // If able to open the file
		// While the game is unfinished and not to the end of the file,
		// keep looping
       
		while(gB.gameState() == UNFINISHED && !inputFile.eof()) {
			// Read move
			inputFile >> row;
			inputFile >> col;
            
			// Make move if square is not occupied
			if(gB.makeMove(row, col, firstMove)) {
				// Check if a draw and not end of file
				if(gB.gameState() == DRAW){
					inputFile.close();
					return true;
				}
				// Check if 'x' won and not end of file
				if(gB.gameState() == X_WON && !inputFile.eof()){
					inputFile.close();
					return false;
				}
				// Check if 'o' won and not end of file
				if(gB.gameState() == O_WON && !inputFile.eof()){
					inputFile.close();
					return false;
				}

				// Change the player
				changePlayer(firstMove);
				gB.print();
               
			}
			else { // Square occupied, return false
				inputFile.close();
				return false;
			}
		}
	}
	else { // File was unable to open
		return false;
	}
    
	// Close file
	inputFile.close();
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
