
#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
#include "Enums/ShipTypes.h"
#include <list>
#include <iostream>


/// @brief Class that represents a board
class Board{ 
    /// @brief ships is a list of ships on the board
    list<Ship> ships;

    /// @brief shots is a matrix of shots on the board
    vector<vector<char>> shots;
    
public :
    /// @brief Construct a new Board object
    Board();

    /// @brief Check if the game is over
    /// @return true if the game is over, false otherwise
    bool is_over();

    /// @brief Shoot at a certain position
    /// @param x the x coordinate of the position
    /// @param y the y coordinate of the position
    /// @return true if a ship is hit at the position, false otherwise
    bool shoot(int x, int y);

    /// @brief Check if a certain position is empty
    /// @param x the x coordinate of the position
    /// @param y the y coordinate of the position
    /// @return true if the position is empty, false otherwise
    bool case_vide(int x, int y);
    
    /// @brief Display the board for the player
    void display_own();

    /// @brief Display the board for the opponent (without ships displayed, only shots)
    void display_for_opponent();

    /// @brief Get the ships object
    /// @return list<Ship> the list of ships on the board
    list<Ship> get_ships();

    /// @brief Set the ships object
    /// @param _ships the list of ships to set as ships
    void set_ships(list<Ship> _ships);

    /// @brief Add a ship to the board
    /// @param ship the ship to add
    void add_ship(Ship* ship);

    /// @brief Check if a ship can be placed at a certain position
    /// @param x the x coordinate of the position
    /// @param y the y coordinate of the position
    /// @param size the size of the ship
    /// @param dir the direction of the ship
    bool can_place_ship(int x, int y, int size, Direction dir);

    /// @brief Get a pair of coordinates from a string
    /// @param coord the string to convert (ex : "D4")
    /// @return pair<int, int> the pair of coordinates ( "D4" -> (4,4) )
    static pair<int, int> get_coords(string coord);
};

#endif // BOARD_H