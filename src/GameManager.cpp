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
    string target;
    clear();
    cout << "Bienvenue dans la bataille navale" << endl;
    while (!is_over()) {
        string player = a_to_play ? "A" : "B";
        Board& own_board = a_to_play ? boardA : boardB;
        Board& opponent_board = a_to_play ? boardB : boardA;

        #ifdef USE_COLOR_IN_CONSOLE
            cout << "\033[1;31mAu tour du joueur " << player << "\033[0m" << endl;
        #else
            cout << "Au tour du joueur " << player << endl;
        #endif

        cout << "Es-tu pret ? Appuie sur entree pour commencer " << endl;
        cin.get(); // Attend une seule fois l'entrée de l'utilisateur
        cout << "Ton plateau" << endl;
        own_board.display_own();
        cout << "Le plateau adverse" << endl;
        opponent_board.display_for_opponent();
        cout << "Entrer la case visée (ex : D4)" << endl;
        cin >> target;
        pair<int, int> coord = Board::get_coords(target);
        int x = coord.first;
        int y = coord.second;
        if (x == -1 || y == -1){
            cout << "Coordonnees invalides" << endl;
            continue;
        }
        opponent_board.shoot(x, y);
        opponent_board.display_for_opponent();

        cout << "Appuye sur entree pour finir ton tour"<<endl;
        cin.ignore();
        cin.get();
        clear();
        cout << "Fin du tour"<< endl;
        a_to_play=!a_to_play;
    }
    // The game is over, one of the players has all his boats dead
    if (boardA.all_boats_dead()){
        #ifdef USE_COLOR_IN_CONSOLE
            cout << "\033[1;31mLe joueur B a gagne\033[0m"<< endl;
        #else
            cout << "Le joueur B a gagne"<< endl;
        #endif
    } else {
        #ifdef USE_COLOR_IN_CONSOLE
            cout << "\033[1;31mLe joueur A a gagne\033[0m"<< endl;
        #else
            cout << "Le joueur A a gagne"<< endl;
        #endif
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
    system("clear");
}