// Final Submission 
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file


#include <iostream>
#include <string>
using namespace std;

#include "globals.h"
#include "GameState.h"

// Function prototype for playMove
void playMove(GameState&);

// The main function
int main() {

    /**********************************************************************************/
    /* Create an initialized game state object                                        */
    /**********************************************************************************/
    GameState game_state;
    // Read two integers from the user that represent the row and column
    // the player would like to place an X or an O in
    // You can assume there will be no formatting errors in the input

    int row;
    int col;
    while (!game_state.get_gameOver()) {
        cout << "Enter row and column of a grid cell: ";
        cin >> row >> col;
        
        // Check that the read row and column values are valid grid coordinates
        if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) {
            cout << "Invalid board coordinates " << row << " " << col << endl;
           continue;
        }
        // The coordinates are valid; set the selectedRow and selectedColumn
        // members of the game state to the read values
        // Again, the corresponding mutators of GameState must be first
        // implemented before this works
            
        game_state.set_selectedRow(row);
        game_state.set_selectedColumn(col);
            
        int selectedRow = game_state.get_selectedRow();
        int selectedCol = game_state.get_selectedColumn();
        
        playMove(game_state);
            
        if (game_state.get_gameOver()) {
            if (game_state.get_turn()) {
                
                cout << "Selected row " << selectedRow << " and column " << selectedCol << endl;
                cout << "Game state after playMove:" << endl;
                cout << "Board:" << endl;
                
                for (int i=0; i<3; i++) {
                    cout << "   ";
                    for (int j=0; j<3; j++) {
                        if (game_state.get_gameBoard(i,j)==X) {
                            cout << "X ";
                        }
                        else if (game_state.get_gameBoard(i,j)==O) {
                            cout << "O ";
                        }
                        else {
                            cout << "B ";
                        }
                    }
                    cout << endl;
                }
         //If move is valid, output is true, if not, it is false
         if (game_state.get_moveValid() == 1) {
            cout << "moveValid: " << "true" << endl;
         }
        else if (game_state.get_moveValid() == 0) {
            cout << "moveValid: " << "false" << endl;
         }
        //If game is over, output is true, if not, it is false
         if (game_state.get_gameOver() == 1) {
            cout << "gameOver: " << "true" << endl;
         }
        else if (game_state.get_gameOver() == 0) {
            cout << "gameOver: " << "false" << endl;
         }
                cout << "winCode:" << game_state.get_winCode() << endl;
                break;
            }
            else {
                
                cout << "Selected row " << selectedRow << " and column " << selectedCol << endl;
                cout << "Game state after playMove: " << endl;
                cout << "Board:" << endl;
                
                for (int i=0; i<3; i++) {
                    cout << "   ";
                    for (int j=0; j<3; j++) {
                        if (game_state.get_gameBoard(i,j)==X) {
                            cout << "X ";
                        }
                        else if (game_state.get_gameBoard(i,j)==O) {
                            cout << "O ";
                        }
                        else {
                            cout << "B ";
                        }
                    }
                    cout << endl;
                }
         //If move is valid, output is true, if not, it is false       
         if (game_state.get_moveValid() == 1) {
            cout << "moveValid: " << "true" << endl;
         }
        else if (game_state.get_moveValid() == 0) {
            cout << "moveValid: " << "false" << endl;
         }
         //If game is over, output is true, if not, it is false
         if (game_state.get_gameOver() == 1) {
            cout << "gameOver: " << "true" << endl;
         }
        else if (game_state.get_gameOver() == 0) {
            cout << "gameOver: " << "false" << endl;
         }
                cout << "winCode:" <<game_state.get_winCode() << endl;
                break;
            }
        }
            
        //ECE244: add code here
        cout << "Selected row " << selectedRow << " and column " << selectedCol << endl;
        cout << "Game state after playMove:" << endl;
        cout << "Board:" << endl;
        
        for (int i=0; i<3; i++) {
            cout << "   ";
            for (int j=0; j<3; j++) {
                if (game_state.get_gameBoard(i,j)==X) {
                    cout << "X ";
                }
                else if (game_state.get_gameBoard(i,j)==O) {
                    cout << "O ";
                }
                else {
                    cout << "B ";
                }
            }
            cout << endl;
        }

        //If move is valid, output is true, if not, it is false
         if (game_state.get_moveValid() == 1) {
            cout << "moveValid: " << "true" << endl;
         }
        else if (game_state.get_moveValid() == 0) {
            cout << "moveValid: " << "false" << endl;
         }
         //If game is over, output is true, if not, it is false
         if (game_state.get_gameOver() == 1) {
            cout << "gameOver: " << "true" << endl;
         }
        else if (game_state.get_gameOver() == 0) {
            cout << "gameOver: " << "false" << endl;
         }
        
        cout << "winCode: " << game_state.get_winCode() << endl;
        cout << endl;
            
    }
    
    return 0;
}