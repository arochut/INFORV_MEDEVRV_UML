
#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
#include "Enums/ShipTypes.h"
#include <list>
#include <iostream>

class Board{
    list<Ship> ships;
    vector<vector<char>> shots;
    
public :
    Board();

    bool is_over();
    bool shoot(int x, int y);
    bool case_vide(int x, int y);
    
    void display_own();
    void display_for_opponent();

    list<Ship> get_ships();
    void set_ships(list<Ship> _ships);
    void add_ship(Ship* ship);
    bool can_place_ship(int x, int y, int size, Direction dir);
    static pair<int, int> get_coords(string coord);
};

#endif // BOARD_H