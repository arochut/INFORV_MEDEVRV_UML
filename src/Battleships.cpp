
#include "Battleships.h"
#include "BoardFactory.h"
#include "GameManager.h"

int main() {
	// IF USE_COLOR_IN_CONSOLE is defined, the text will be printed in color
	#ifdef USE_COLOR_IN_CONSOLE
		cout << "\033[1;31m Bienvenue dans le jeu de la bataille navale ! \033[0m" << endl; // Prints the text in red if the terminal supports it
	#else
		cout << "Bienvenue dans le jeu de la bataille navale !" << endl; // Prints the text in red if the terminal supports it
	#endif
	
	BoardFactory boardFactory = BoardFactory();
	Board boardA = boardFactory.create_board();
	Board boardB = boardFactory.create_board();
	GameManager gameManager = GameManager(boardA, boardB);
	gameManager.play();
	return 0;
}
