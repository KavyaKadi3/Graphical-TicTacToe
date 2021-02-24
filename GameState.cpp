//Final Submission
//  GameState.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//

#include "globals.h"
#include "GameState.h"

//Obtaining rows and columns
int GameState::get_selectedColumn() {
    return selectedColumn;
}
int GameState::get_selectedRow() {
    return selectedRow;
}

//Obtaining valid move, game over, turn and win code
bool GameState::get_moveValid() {
    return moveValid;
}
bool GameState::get_gameOver() {
    return gameOver;
}
bool GameState:: get_turn() {
    return turn;
}
int GameState::get_winCode() {
    return winCode;
}

//Setting up rows and columns
void GameState::set_selectedRow(int value) {
   selectedRow=value;
}
void GameState::set_selectedColumn(int value) {
   selectedColumn=value;
}

//Setting up valid move, game over, turn and win code
void GameState::set_moveValid(bool value) {
    moveValid=value;
}
void GameState::set_gameOver(bool value) {
    gameOver=value;
}
void GameState::set_turn(bool value) {
    turn=value;
}
void GameState::set_winCode(int value) {
    winCode=value;
}

//Obtaining and setting game board
int GameState::get_gameBoard(int row, int col) {
     return gameBoard[row][col];
}
void GameState:: set_gameBoard(int row, int col, int value) {
    gameBoard[row][col]=value;
}

//Game State Constructor
GameState::GameState() {
    selectedRow = 0;
    selectedColumn = 0;
    moveValid = true;
    gameOver = false;
    turn = true;
    winCode= 0;
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            gameBoard[i][j]=0;
        }
    }
}