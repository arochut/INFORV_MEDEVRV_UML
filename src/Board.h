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
};