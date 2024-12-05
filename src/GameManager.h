
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"


/// @brief Class that manages the game
class GameManager{
public:
    /// @brief boardA is the board of player A
    Board boardA;
    /// @brief boardB is the board of player B
    Board boardB;
    /// @brief a_to_play is a boolean that indicates if it is player A's turn (otherwise it is player B)
    bool a_to_play;
public:
    /// @brief Construct a new GameManager object
    GameManager(Board _boardA, Board _boardB);

    /// @brief Check if the game is over
    bool is_over();

    /// @brief Play a game of battleship
    void play();

    /// @brief Get the boardA object
    /// @return Board
    Board get_boardA();

    /// @brief Set the boardA object
    /// @param _boardA the board to set as boardA
    void set_boardA(Board _boardA);

    /// @brief Get the boardB object
    /// @return Board
    Board get_boardB();

    /// @brief Set the boardB object
    /// @param _boardB the board to set as boardB
    void set_boardB(Board _boardB);

    /// @brief Get the a_to_play object
    /// @return bool
    bool get_turn();

    /// @brief Set the a_to_play bool
    /// @param _turn the bool to set as a_to_play (true for player A, false for player B)
    void set_turn(bool _turn);

    void clear();
};

#endif