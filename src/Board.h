#include "Ship.h"
#include "ShipTypes.h"
#include <list>

class Board{
public :
    list<Ship> ships;

    Board();
    bool is_over();
    bool shoot(int x, int y);
    bool case_vide(int x, int y);
    void display();
};