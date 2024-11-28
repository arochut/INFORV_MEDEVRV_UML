#include "Board.h"

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
            if (it->is_dead()){
                cout << "Touché-Coulé" << endl;
            } else {
                cout << "Touché" << endl;
            }
            return true;
        }
    }
    cout << "Raté" << endl;
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
            bool is_occupied = false;
            for (list<Ship>::iterator it=ships.begin(); it!=ships.end(); it++){
                if(it->occupies(i,j)){
                    is_occupied = true;
                    if((it->is_hit(i,j))){
                        cout<<" | X";
                    }else {
                        cout<<" | S";
                    }
                }
            }
            if (!is_occupied){
                cout<<" |  ";
            }
        }
        cout<<endl;
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

void Board::addShip(Ship* ship)
{
    ships.push_back(*ship);
}

bool Board::can_place_ship(int x, int y, int size, Direction dir)
{
    if (dir == Direction::Horizontal){
        if (x+size-1>10){
            return false;
        }
        for (int i=0; i<size; i++){
            if (!case_vide(x+i,y)){
                return false;
            }
        }
    } else {
        if (y+size-1>10){
            return false;
        }
        for (int i=0; i<size; i++){
            if (!case_vide(x,y+i)){
                return false;
            }
        }
    }
    return true;
}

pair<int, int> Board::get_coords(string coord)
{
    if (coord.length() != 2){
        return make_pair(-1,-1);
    }
    int x = coord[0] - 'A' + 1;
    int y = coord[1] - '0';
    if (x < 1 || x > 10 || y < 1 || y > 10){
        return make_pair(-1,-1);
    }
    return make_pair(x,y);
}
