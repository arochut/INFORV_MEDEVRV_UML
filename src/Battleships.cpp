
#include "Battleships.h"
#include "BoardFactory.h"
#include "GameManager.h"

int main() {
	BoardFactory boardFactory = BoardFactory();
	Board boardA = boardFactory.create_board();
	Board boardB = boardFactory.create_board();

	return 0;
}
