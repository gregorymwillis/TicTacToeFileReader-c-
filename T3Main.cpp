// Main function for T3Reader program

#include "T3Reader.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	T3Reader game1;
	cout << game1.readGameFile("pWinEof.txt") << endl; // true 1

	T3Reader game2('o');
	cout << game2.readGameFile("pWinEof.txt") << endl; // true 1

	T3Reader game3;
	cout << game3.readGameFile("pWinNotEof.txt") << endl; // false 0

	T3Reader game4('o');
	cout << game4.readGameFile("pWinNotEof.txt") << endl; // false 0

	T3Reader game5;
	cout << game5.readGameFile("drawNeof.txt") << endl; //false 0

    T3Reader game6;
    cout << game6.readGameFile("drawEof.txt") << endl; //true 1
    
	T3Reader game7;
	cout << game7.readGameFile("sqTaken.txt") << endl; // false 0

	return 0;
}
