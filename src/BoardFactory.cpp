#include "BoardFactory.h"

using namespace std;

BoardFactory::BoardFactory() {
}




void BoardFactory::place_ship(Board& board, ShipType type) {
    bool input_correct = false;
    pair<int, int> xy = make_pair(-1, -1);
    Direction dir;
    while(!input_correct)  {
        #ifdef USE_COLOR_IN_CONSOLE
            cout << "Ou voulez-vous placer votre \033[1;36m" << type.name << "\033[0m (taille " << type.size << ") ?" << endl;
        #else
            cout << "Ou voulez-vous placer votre " << type.name << " (taille " << type.size << ") ?" << endl;
        #endif
        board.display_own();
        cout << "Entrez les coordonnees sous la forme 'B4' :" << endl;
        string coord;
        cin >> coord;
        char d;
        cout << "Entrez la direction du bateau (h pour horizontal, v pour vertical) :" << endl;
        cin >> d;
        xy = Board::get_coords(coord);
        if (xy.first != -1 && xy.second != -1) {
            input_correct = true;
        } else {
            #ifdef USE_COLOR_IN_CONSOLE
                cout << "\033[1;31mCoordonnees invalides\033[0m" << endl;
            #else
                cout << u8"Coordonnees invalides" << endl;
            #endif
                
        }
        if (d == 'h') {
            dir = Direction::Horizontal;
        } else if (d == 'v') {
            dir = Direction::Vertical;
        }
        else {
            cout << "Direction invalide" << endl;
            xy = make_pair(-1, -1);
            input_correct = false;
        }
        

        if (input_correct && board.can_place_ship(xy.first, xy.second, type.size, dir)) {
                board.add_ship(new Ship(xy.first, xy.second, type.size, dir, type.name));
            } else {
                cout << "Impossible de placer le bateau ici" << endl;
                input_correct = false;
            }
        }
    }
void BoardFactory::place_all_ships(Board& board) {
    for (int i = 0; i < ShipTypes::SHIP_COUNT; i++) {
        place_ship(board, ShipTypes::SHIP_TYPES[i]);
        system("clear");
    }
    #ifdef USE_COLOR_IN_CONSOLE
        cout << "\033[1;32mTous les bateaux sont en place\033[0m" << endl;
        cout << "Voici votre plateau de jeu :" << endl;
    #else
        cout << "Tous les bateaux sont en place" << endl;
        cout << "Voici votre plateau de jeu :" << endl;
    #endif
    board.display_own();
}

Board BoardFactory::create_board() {
    Board board;
    place_all_ships(board);
    return board;
}