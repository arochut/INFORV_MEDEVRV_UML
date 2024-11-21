
#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H

#include <iostream>

#include "Board.h"
#include "Ship.h"
#include "ShipTypes.h"

using namespace std;


class BoardFactory {
public:
    BoardFactory();
    Board create_board();

private : 
    void place_ship(Board& board, ShipType type);

    void place_all_ships(Board& board);
};

#endif
