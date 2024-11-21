#include "GameManager.h"

bool GameManager::is_over()
{
    if(boardA.is_over() || boardB.is_over()){
        return true;
    }
    return false;
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
    return turn;
}

void GameManager::set_boardA(bool _turn)
{
    turn=_turn;
}
