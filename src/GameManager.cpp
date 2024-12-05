#include "GameManager.h"

GameManager::GameManager()
{
    boardA = Board();
    boardB = Board();
    a_to_play=true;
}
 
bool GameManager::is_over()
{
    if(boardA.is_over() || boardB.is_over()){
        return true;
    }
    return false;
}

void GameManager::play_turn()
{
    string bullet;
    while (!is_over()){
        if (a_to_play){
            cout << "Au tour du joueur A"<< endl;
        }else {
            cout << "Au tour du joueur B"<< endl;
        }
        cout << "Entrer la case visée (ex : D4)" <<endl;
        cin >> bullet;
        int x = bullet[0] - 'A' + 1;
        int y = bullet[1] - '0';
        if (a_to_play){
            boardB.shoot(x,y);
        }else {
            boardA.shoot(x,y);
        }
        cout << "Fin du tour"<< endl;
        a_to_play=!a_to_play;
    }
}

Board GameManager::get_boardA()
{
    return boardA;
}

void GameManager::set_boardA(Board _boardA)
{
    boardA=_boardA;
}

Board GameManager::get_boardB()
{
    return boardB;
}

void GameManager::set_boardB(Board _boardB)
{
    boardB=_boardB;
}

bool GameManager::get_turn()
{
    return a_to_play;
}

void GameManager::set_turn(bool _turn)
{
    a_to_play=_turn;
}
