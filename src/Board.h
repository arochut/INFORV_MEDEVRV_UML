#include "Ship.h"
#include "BoatTypes.h"

class Board{
public :
    ships : list<Ship>;

    Board();
    bool is_over();
    bool shoot(int x, int y);
    bool case_vide(int x, int y);
    void display();
};