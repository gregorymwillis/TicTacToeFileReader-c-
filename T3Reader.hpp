/*********************************************************************************
** Name: Greg Willis
** Date: 11/19/2017
** Description: (T3Reader.hpp) This is the header file that creates a class
**		that uses the Board class to re-run a game of tic-tac-toe that 
**		it reads from a text file.
********************************************************************************/
#ifndef T3READER_HPP
#define T3READER_HPP

#include "Board.hpp"
#include <string>

using std::string;

class T3Reader {

	private:
		// Board object
		Board gB;
		// Keeps track of which player has first move
		char firstMove;
		// Functions switches players' turn
		void changePlayer(char &);

	public:
		// Constructors
		T3Reader();
		T3Reader(char);

		// Reads the file containing the moves of the game
		bool readGameFile(string);

};
#endif
