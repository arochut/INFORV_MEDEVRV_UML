#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{

}

bool Board::is_over()
{
    for(list<Ship>::iterator it=ships.begin(); it!=ships.end(); it++){
        if(!(*it)->is_dead()){
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
