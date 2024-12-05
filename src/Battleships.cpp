
#include "Battleships.h"
#include "BoardFactory.h"
#include "GameManager.h"

int main() {
	BoardFactory boardFactory = BoardFactory();
	Board boardA = boardFactory.create_board();
	Board boardB = boardFactory.create_board();
	GameManager gameManager = GameManager(boardA, boardB);
	gameManager.play();
	return 0;
}
