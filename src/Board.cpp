#include "Board.h"
#include "ShipTypes.h"
#include <iostream>
using namespace std;

Board::Board()
{
    ships = list<Ship>();
}

bool Board::is_over()
{
    for(list<Ship>::iterator it=ships.begin(); it!=ships.end(); it++){
        if(!(*it).is_dead()){
            return false;
        }
    }
    return true;
}

bool Board::shoot(int x, int y)
{
    for(list<Ship>::iterator it=ships.begin(); it!=ships.end(); it++){
        for(int i=0; i<(*it).get_size(); i++){

        }
    }
}

bool Board::case_vide(int x, int y)
{
    return false;
}

void Board::display()
{
    cout << "bonne chance"<<endl;
}

list<Ship> Board::get_ships()
{
    return ships;
}

void Board::set_ships(list<Ship> _ships)
{
    ships=_ships;
}
