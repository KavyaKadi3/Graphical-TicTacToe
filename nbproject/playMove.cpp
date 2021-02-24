//Final Submission
//  playMove.cpp
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
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state) {
    //Initializing local variables
    int playerTurn=0;
    int row = game_state.get_selectedRow();
    int col = game_state.get_selectedColumn();

//Initial settings; if board isn't empty, set everything to default (game is not over, player hasn't won, move is not valid)
if (game_state.get_gameBoard(row, col) != Empty) {
    game_state.set_moveValid(false);
    game_state.set_gameOver(false);
    game_state.set_winCode(0);
    return;
}
    
   if (game_state.get_turn() == 1) {
        game_state.set_gameBoard(row, col, 1);
                playerTurn=1;
    }
    
    else {
        game_state.set_gameBoard(row, col, -1);
                playerTurn=-1;
    }
         //If the move made by user is valid
        game_state.set_moveValid(true);
        bool success = true;
        int i;
        
        //Checking rows to see if user input creates 3 X's or O's in a row
        for(i=0; i<=2; i++) {
            if (game_state.get_gameBoard(row, i) !=playerTurn) {
                game_state.set_winCode(0);
                success=false;
                break;
            }
        }
        //If program finds that there are 3 X or O's in a row, it adds 1 to value of row to get winCode
        if (success) {
            game_state.set_gameOver(true);
            game_state.set_winCode(row +1);
            return;
        }
        success=true; //Establishing that we have a matching row
        
        //Checking columns to see if user input creates 3 X's or O's in a column
        for(i=0; i<=2; i++) {
            if (game_state.get_gameBoard(i, col) != playerTurn) {
                game_state.set_winCode(0);
                success=false;
                break;
            }
        }
        //Depending on row, the winCode varies (add 3 to value of row)
        if (success) {
            game_state.set_gameOver(true);
            game_state.set_winCode(row+3);
            return;
        }
        success = true;

        bool validMove = game_state.get_moveValid();
        //checking diagonal
        if(validMove== true){
            if ((game_state.get_gameBoard(2,2) == O && game_state.get_gameBoard(1,1) == O && game_state.get_gameBoard(0,0) == O) || (game_state.get_gameBoard(2,2) == X && game_state.get_gameBoard(1,1) == X && game_state.get_gameBoard(0,0) == X)) {
                game_state.set_gameOver(true);
                game_state.set_winCode(7);
            }
         //checking diagonal in other direction
        else if ((game_state.get_gameBoard(2,0) == O && game_state.get_gameBoard(1,1) == O && game_state.get_gameBoard(0,2) == O) || (game_state.get_gameBoard(2,0) == X && game_state.get_gameBoard(1,1) == X && game_state.get_gameBoard(0,2) == X)) {
                game_state.set_gameOver(true);
                game_state.set_winCode(8); 
        }
            }
        
          if (game_state.get_turn()) {
            game_state.set_turn(false);
        }
        else {
            game_state.set_turn(true);
        }
        
            }
      