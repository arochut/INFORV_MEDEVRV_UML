
#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H

#include <iostream>

#include "Board.h"
#include "Ship.h"
#include "ShipTypes.h"

using namespace std;


/// @brief Class that creates a board interactively
class BoardFactory {
public:
    /// @brief Construct a new BoardFactory object
    BoardFactory();

    /// @brief Interactivly create a board object
    /// @return Board the created board
    Board create_board();

private : 
    /// @brief Place a ship of a certain type on a board
    /// @param board the board to place the ship on
    /// @param type the type of the ship to place
    void place_ship(Board& board, ShipType type);

    /// @brief Place all ships on a board
    void place_all_ships(Board& board);
};

#endif
