
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"


class GameManager{

    Board boardA;
    Board boardB;
    bool turn;
public:
    GameManager();
    bool is_over();
    Board get_boardA();
    void set_boardA(Board _boardA);
    Board get_boardB();
    void set_boardB(Board _boardB);
    bool get_turn();
    void set_boardA(bool _turn);

};

#endif