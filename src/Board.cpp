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
        if((*it).hit(x,y)){
            return true;
        }
    }
    return false;
}

bool Board::case_vide(int x, int y)
{
    for(list<Ship>::iterator it=ships.begin(); it!=ships.end(); it++){
        if (it->occupies(x,y)){
            return false;
        }
    }
    return true;
}

void Board::display()
{
    string grid[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    cout << "    1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 "<<endl;
    for(int i=1; i<11;i++){
        cout<< grid[i-1];
        for(int j=1; j<11;j++){
            for (list<Ship>::iterator it=ships.begin(); it!=ships.end(); it++){
                if(it->occupies(i,j)){
                    if((it->get_hits())[j-it->get_x_start() + i-it->get_y_start()]){
                        cout<<" | X";
                    }else {
                        cout<<" | S";
                    }
                } else {
                    cout << " |  ";
                }
            }
            cout<<endl;
        }
    }
}

list<Ship> Board::get_ships()
{
    return ships;
}

void Board::set_ships(list<Ship> _ships)
{
    ships=_ships;
}
