#include "Board.h"
#include <iostream>

using namespace std;

Board::Board()
{
    ships = list<Ship>();
    shots = vector<vector<int>>(10, vector<int>(10, 0));
}

bool Board::all_boats_dead()
{
    for (list<Ship>::iterator it=ships.begin(); it!=ships.end(); it++){
        if (!it->is_dead()){
            return false;
        }
    }
    return true;
}

bool Board::shoot(int x, int y)
{
    for(list<Ship>::iterator it=ships.begin(); it!=ships.end(); it++){
        if((*it).hit(x,y)){
            shots[x-1][y-1] = 2; // Record hit
            if (it->is_dead()){
                #ifdef USE_COLOR_IN_CONSOLE
                    cout << "\033[1;31mTouché-Coulé\033[0m" << endl;
                #else
                    cout << "Touché-Coulé" << endl;
                #endif
            } else {
                #ifdef USE_COLOR_IN_CONSOLE
                    cout << "\033[1;31mTouché\033[0m" << endl;
                #else
                    cout << "Touché" << endl;
                #endif
            }
            display_for_opponent();
            return true;
        }
    }
    shots[x-1][y-1] = 1; // Record miss
    #ifdef USE_COLOR_IN_CONSOLE
        cout << "\033[1;34mRaté\033[0m" << endl;
    #else
        cout << "Raté" << endl;
    #endif
    display_for_opponent();
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

void Board::display_own()
{
    string grid[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    cout << "    1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 "<<endl;
    for(int i=1; i<11;i++){
        cout<< grid[i-1];
        for(int j=1; j<11;j++){
            if (case_vide(j,i)){
                cout<<" |  ";
            } else {
                if(shots[j-1][i-1] == 0){
                    #ifdef USE_COLOR_IN_CONSOLE
                        cout << " | \033[1;36mS\033[0m";
                    #else
                        cout<<" | S";
                    #endif
                }
                else if(shots[j-1][i-1] == 2){
                    #ifdef USE_COLOR_IN_CONSOLE
                        cout << " | \033[1;31mX\033[0m";
                    #else
                        cout <<" | X";
                    #endif
                }
            }
        }    
        cout<<endl;
    }
}

void Board::display_for_opponent()
{
    string grid[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    cout << "    1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 "<<endl;
    for(int i=1; i<11;i++){
        cout<< grid[i-1];
        for(int j=1; j<11;j++){
            if(shots[j-1][i-1] == 0){
                cout<<" |  ";
            }else if(shots[j-1][i-1] == 1){
                #ifdef USE_COLOR_IN_CONSOLE
                    cout << " | \033[1;34mO\033[0m";
                #else
                    cout<<" | O";
                #endif
            }else{
                #ifdef USE_COLOR_IN_CONSOLE
                    cout << " | \033[1;31mX\033[0m";
                #else
                    cout<<" | X";
                #endif
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

void Board::add_ship(Ship* ship)
{
    ships.push_back(*ship);
}

bool Board::can_place_ship(int x, int y, int size, Direction dir)
{
    cout << "Essaie de placer un bateau de taille " << size << " en (" << x << "," << y << ")" << endl;
    if (dir == Direction::Horizontal){
        if (x + size - 1 > 10){
            return false;
        }
        for (int i = 0; i < size; i++){
            if (!case_vide(x+i, y)){
                return false;
            }
        }
    } else {
        if (y + size - 1 > 10){
            return false;
        }
        for (int i = 0; i < size; i++){
            if (!case_vide(x, y+i)){
                return false;
            }
        }
    }
    
    return true;
}

/// @brief Returns a pair of ints from a string of coordinates (ex : "A4" -> (4,1))
/// @param coord string of coordinates
/// @return pair<int, int> pair of ints
pair<int, int> Board::get_coords(string coord)
{
    if (coord.length() != 2){
        return make_pair(-1,-1);
    }
    int y = coord[0] - 'A' + 1;
    int x = coord[1] - '0';
    if (x < 1 || x > 10 || y < 1 || y > 10){
        return make_pair(-1,-1);
    }
    return make_pair(x,y);
}
