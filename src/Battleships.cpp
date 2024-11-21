
#include "Battleships.h"

int main() {
	
	Board boardA = Board();
	Ship* ship = new Ship(5, 5, 3, Direction::Horizontal, "Anatole");
	boardA.addShip(ship);
	boardA.display();

	return 0;
}
