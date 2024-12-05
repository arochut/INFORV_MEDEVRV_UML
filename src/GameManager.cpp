#include "GameManager.h"

GameManager::GameManager(Board _boardA, Board _boardB)
{
    boardA = _boardA;
    boardB = _boardB;
    a_to_play = true;
}

 
bool GameManager::is_over()
{
    return (boardA.all_boats_dead() || boardB.all_boats_dead());
}

void GameManager::play()
{
    string bullet;
    cout << "Bienvenue dans la bataille navale"<< endl;
    while (!is_over()){
        if (a_to_play){
            cout << "Au tour du joueur A"<< endl;
            cout << "Ton plateau"<< endl;
            boardA.display_own();
            cout << "Le platau adverse"<< endl;
            boardB.display_for_opponent();
        }else {
            cout << "Au tour du joueur B"<< endl;
            cout << "Ton plateau"<< endl;
            boardB.display_own();
            cout << "Le platau adverse"<< endl;
            boardA.display_for_opponent();
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

    cout << "Fin de la partie"<< endl;
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
