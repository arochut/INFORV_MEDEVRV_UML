#include "Board.h"
#include <iostream>
using namespace std;

bool Board::is_over()
{
    for(Ship ship in ships){
        if(!ship.is_dead()){
            return false;
        }
    }
    return true;
}

bool Board::shoot(int x, int y)
{
    return false;
}

bool Board::case_vide(int x, int y)
{
    return false;
}

void Board::display()
{
    cout << "bonne chance"<<endl;
}
