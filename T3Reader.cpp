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

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

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
    GmState status = gB.gameState();

	if(inputFile) { // If able to open the file
		// While the game is unfinished and not to the end of the file,
		// keep looping
        cout << "file opened" << endl;
        cout << "status " << status << endl;
        cout << "input file eof " << inputFile.eof() << endl;
		while(gB.gameState() == UNFINISHED && !inputFile.eof()) {
			// Read move
			inputFile >> row;
			inputFile >> col;
            cout << "in while" << endl;
            
			// Make move if square is not occupied
			if(gB.makeMove(row, col, firstMove)) {
				// Check if a draw and not end of file
				if(gB.gameState() == DRAW && !inputFile.eof()){
                    cout << "draw, not eof" << endl;
					inputFile.close();
					return false;
				}
				// Check if 'x' won and not end of file
				if(gB.gameState() == X_WON && !inputFile.eof()){
                    cout << "x won, not eof" << endl;
					inputFile.close();
					return false;
				}
				// Check if 'o' won and not end of file
				if(gB.gameState() == O_WON && !inputFile.eof()){
                    cout << "o won, not eof" << endl;
					inputFile.close();
					return false;
				}

				// Change the player
				changePlayer(firstMove);
				gB.print();
                cout << "status " << status << endl;
                cout << "input file eof " << inputFile.eof() << endl;
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
    cout << "out of while" << endl;
    cout << "status " << status << endl;
    cout << "input file eof " << inputFile.eof() << endl;
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
