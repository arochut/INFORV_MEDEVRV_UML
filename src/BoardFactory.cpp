#include "BoardFactory.h"

using namespace std;

BoardFactory::BoardFactory() {
}




void BoardFactory::place_ship(Board& board, ShipType type) {
    bool input_correct = false;
    pair<int, int> xy = make_pair(-1, -1);
    Direction dir;
    while(!input_correct)  {
    cout << "Ou voulez-vous placer votre " << type.name << " (taille " << type.size << ") ?" << endl;
    board.display_own();
    cout << "Entrez les coordonnées sous la forme 'B4' :" << endl;
        string coord;
        cin >> coord;
        char d;
    cout << "Entrez la direction du bateau (h pour horizontal, v pour vertical) :" << endl;
        cin >> d;
        xy = Board::get_coords(coord);
        if (xy.first != -1 && xy.second != -1) {
            input_correct = true;
        } else {
            cout << "Coordonnées invalides" << endl;
        }
        if (d == 'h') {
            dir = Direction::Horizontal;
        } else if (d == 'v') {
            dir = Direction::Vertical;
        }
        else {
            cout << "Direction invalide" << endl;
            xy = make_pair(-1, -1);
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
    }
    cout << "Tous les bateaux ont été placés" << endl;
    cout << "Voici votre plateau de jeu :" << endl;
    board.display_own();
}

Board BoardFactory::create_board() {
    Board board;
    place_all_ships(board);
    return board;
}