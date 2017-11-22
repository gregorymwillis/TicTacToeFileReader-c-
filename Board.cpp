/***********************************************************************************
** Name: Greg Willis
** Date: 11/18/2017
** Description: (Board.cpp) This class represents a tic-tac-toe board. It has a 3X3
**		array to store players' moves. This is the implementation file of
**		the class.
***********************************************************************************/
#include "Board.hpp"
#include <stdio.h>
#include <ctype.h>
#include <iostream>

using std::cout;
using std::endl;

// Default constructor sets gameBoardArray to empty spaces
Board::Board() {
	for(int r = 0; r < 3; r++) {
		for(int c = 0; c < 3; c++) {
			gameBoardArray[r][c] = ' ';
		}
	}
}

// Function takes three parameters. The row, column and char to be placed into
// The gameBoardArray
bool Board::makeMove(int r, int c, char m) {

	// Check if spot has 'x' or 'o'
	if (gameBoardArray[r][c] != ' ') {
		return false;
	}
	// If spot empty, place 'x' or 'o' into spot
	else {
		// Make passed-in char lowercase
		gameBoardArray[r][c] = tolower(m);
		return true;
	}
}

// Function checks for four conditions of the game. 1. See if 'x' won 2. See
// if 'o' won. 3. See if game is a draw. 4. See if game is unfinished. It then
// returns the state of the game.
GmState Board::gameState() {
	// GmState {X_WON, O_WON, DRAW, UNFINISHED}
	// Create char x and char o
	char x = 'x', o = 'o';

	GmState status = UNFINISHED;

	// Check to see if 'x' won
	if(checkRows(x) || checkCols(x) || checkDiag(x)) {
		status = X_WON;
	}
	// Check to see if 'o' won
	if(checkRows(o) || checkCols(o) || checkDiag(o)) {
		status = O_WON;
	}

	// Check to see if game is a draw
	// if game is finished and status is NOT set to X_WON or O_WON
	if(hasEmptySquare() == false && status != X_WON && status != O_WON) {
		status = DRAW;
	}

	// return GmState enum
	return status;
}

// This function searches each row to check for three in a row of the 'x'
// or 'o' passed-in
bool Board::checkRows(char p) {
	// Check each row to see if all subscripts match 'x' or 'o' player passed-in
	bool winner = false;	// Stores bool if all three points match
	char p1, p2, p3;	// Stores char at each point in row
	for(int r = 0; r < 3; r++) {
		// Set each position in row to p1, p2, p3
		p1 = gameBoardArray[r][0];
		p2 = gameBoardArray[r][1];
		p3 = gameBoardArray[r][2];
		// If all points match passed-in 'p', set winner to true
		if(p1 == p && p2 == p && p3 == p) {
			winner = true;
		}

	}
	// Return winner
	return winner;
}

// This function searches each column to check for three in a row of the 'x'
// or 'o' passed-in
bool Board::checkCols(char p) {
	bool winner = false;	// Stores bool if all three points match
	char p1, p2, p3;	// Stores char at each point in column
	for(int c = 0; c < 3; c++) {
		// Set each position in column to p1, p2, p3
		p1 = gameBoardArray[0][c];
		p2 = gameBoardArray[1][c];
		p3 = gameBoardArray[2][c];
		// If all points match passed-in 'p', set winner to true
		if(p1 == p && p2 == p && p3 == p) {
			winner = true;
		}

	}
	// Return winner
	return winner;
}

// This function searches each diagonal to check for three in a row of the 'x'
// or 'o' passed-in
bool Board::checkDiag(char p) {
	bool winner = false;	// Stores bool if all three points match
	char p1, p2, p3;	// Stores char at each point in diagonal
	p1 = gameBoardArray[0][0];
	p2 = gameBoardArray[1][1];
	p3 = gameBoardArray[2][2];
	// If all points match passed-in 'p', set winner to true
	if(p1 == p && p2 == p && p3 == p) {
		winner = true;
	}

	p1 = gameBoardArray[0][2];
	p2 = gameBoardArray[1][1];
	p3 = gameBoardArray[2][0];
	// If all points match passed-in 'p', set winner to true
	if(p1 == p && p2 == p && p3 == p) {
		winner = true;
	}
	// Return winner
	return winner;
}

// Check to see if every spot in the gameBoardArray is used and return true if
// unfinished and false if finished
bool Board::hasEmptySquare() {
	bool nF = false;	// Set not finished to false
	// Check each space in array and see if it holds an empty space
	for(int r = 0; r < 3; r++) {
		for(int c = 0; c < 3; c++) {
			if(gameBoardArray[r][c] == ' ') {
				nF = true;
			}
		}
	}
	// Return if true if a empty space was found or false if empty
	// space was not found
	return nF;
}

// This prints the gameBoardArray
void Board::print() {

	for(int r = 0; r < 3; r++) {
		for(int c = 0; c < 3; c++) {
			// cout << gameBoardArray[r][c];
		}
	}
	cout << endl;
	for(int r = 0; r < 3; r++) {
		cout << gameBoardArray[r][0] << " | " <<
			gameBoardArray[r][1] << " | " <<
			gameBoardArray[r][2] << endl;
		if(r < 2) {
			cout << "__________" << endl;
		}
	}
}
