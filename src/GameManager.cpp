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
    string buffer;
    clear();
    cout << "Bienvenue dans la bataille navale"<< endl;
    while (!is_over()){
        if (a_to_play){
            cout << "Au tour du joueur A"<< endl;
            cout << "Est-tu prêt ? Entre une touche"<<endl;
            cin>>buffer;
            cout << "Ton plateau"<< endl;
            boardA.display_own();
            cout << "Le plateau adverse"<< endl;
            boardB.display_for_opponent();
        }else {
            cout << "Au tour du joueur B"<< endl;
            cout << "Est-tu prêt ? Entre une touche"<<endl;
            cin>>buffer;
            cout << "Ton plateau"<< endl;
            boardB.display_own();
            cout << "Le plateau adverse"<< endl;
            boardA.display_for_opponent();
        }
        cout << "Entrer la case visée (ex : D4)" <<endl;
        cin >> bullet;
        pair<int, int> coord = Board::get_coords(bullet);
        int x = coord.first;
        int y = coord.second;

        if (a_to_play){
            boardB.shoot(x,y);
        }else {
            boardA.shoot(x,y);
        }
        cout << "Entre une touche pour passer"<<endl;
        clear();
        cin>>buffer;
        cout << "Fin du tour"<< endl;
        a_to_play=!a_to_play;
    }
    if (boardA.all_boats_dead()){
        cout << "Le joueur B a gagné"<< endl;
    } else {
        cout << "Le joueur A a gagné"<< endl;
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


void GameManager::clear() {
    cout << string( 100, '\n' );
}