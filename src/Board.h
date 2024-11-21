
#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
#include "ShipTypes.h"
#include <list>

class Board{
    list<Ship> ships;
public :
    Board();
    bool is_over();
    bool shoot(int x, int y);
    bool case_vide(int x, int y);
    void display();
    list<Ship> get_ships();
    void set_ships(list<Ship> _ships);
    void addShip(Ship* ship);
    bool can_place_ship(int x, int y, int size, Direction dir);
    static pair<int, int> get_coords(string coord);
};

#endif // BOARD_H