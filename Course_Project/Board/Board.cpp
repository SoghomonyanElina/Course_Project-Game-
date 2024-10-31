#include "Board.hpp"
#include <ncurses.h>

Board::Board() {
    Board_reset();
}

void Board::Board_print() {
    clear();
    for(size_t i = 0; i < row; ++i) {
        for(size_t j = 0; j < column; ++j) {
            mvprintw(i + 1, j * 2 + 60, " %c ", board[i][j]);
        }
        //std::cout << std::endl;
    }
    refresh();
}

void Board::Board_reset() {
    for(size_t i = 0; i < row; ++i) {
        for(size_t j = 0; j < column; ++j) {
            board[i][j] = 'o';
        }
    }
}

void Board::Set_piece(int row, int column, char symbol) {
    board[row][column] = symbol; 
}

bool Board::checkHorizontalWin() {
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < column - 3; ++j) {
            if(board[i][j] != 'o' && 
               board[i][j] == board[i][j + 1] &&
               board[i][j] == board[i][j + 2] &&
               board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkVerticalWin() {
    for(int j = 0; j < column; ++j) {
        for(int i = 0; i < row - 3; ++i) {
            if(board[i][j] != 'o' &&
               board[i][j] == board[i + 1][j] &&
               board[i][j] == board[i + 2][j] &&
               board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkDiagonalWin() {
    for(int i = 0; i < row - 3; ++i) {
        for(int j = 0; j < column - 3; ++j) {
            if(board[i][j] != 'o' &&
               board[i][j] == board[i + 1][j + 1] &&
               board[i][j] == board[i + 2][j + 2] &&
               board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }
    for(int i = 0; i < row - 3; ++i) {
        for(int j = 3; j < column ; ++j) {
            if(board[i][j] != 'o' &&
               board[i][j] == board[i + 1][j - 1] &&
               board[i][j] == board[i + 2][j - 2] &&
               board[i][j] == board[i + 3][j - 3]) {
                return true;
            }
        }
    }
    return false;
}





