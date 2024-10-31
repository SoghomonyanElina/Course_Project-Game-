#include "GameLogic.hpp"
#include <ncurses.h>

GameLogic::GameLogic(Board* gameBoard,std::string player1_name, std::string player2_name)
        : board_(gameBoard), player_1(nullptr), player_2(nullptr), currentPlayer(nullptr) {
            player_1 = new Player(player1_name, 'X');
            player_2 = new Player(player2_name, 'Y');
            currentPlayer = player_1;
}

GameLogic::~GameLogic() {
    delete player_1;
    delete player_2;
}

void GameLogic::Switch_Player() {
    currentPlayer = (currentPlayer == player_1) ? player_2 : player_1;
    //mvprintw(5, 20,"%s's turn!", currentPlayer->get_name().c_str());
    //refresh();
}

bool GameLogic::is_Available(int column) {
    int row = GetTopEmptyRow(column);
    if(row == -1) {
        return false;
    }
    return true;
}

bool GameLogic::check_Drawgame() {
    for(int j = 0; j < board_->column; ++j) {
        if(board_->board[0][j] == 'o') {
            return false;
        }
    }
    return true;
}

int GameLogic::GetTopEmptyRow(int column) {
    for(int row = board_->row - 1; row >= 0; --row) {
        if(board_->board[row][column - 1] == 'o') {
            return row;
        }
    }
    return -1;
}

bool GameLogic::check_Win() {
    return board_->checkHorizontalWin() || board_->checkVerticalWin() || board_->checkDiagonalWin();
}

void GameLogic::Checking() {
    if(!check_Drawgame() && !check_Win()) {
        Switch_Player();
        mvprintw(5, 20,"%s's turn!", currentPlayer->get_name().c_str());
        refresh();
    }
    return;
}

void GameLogic::Make_move(int column) {
    int row = GetTopEmptyRow(column);
    if(is_Available(column)) {
        board_->Set_piece(row, column - 1, currentPlayer->get_symbol());
        board_->Board_print();
        Checking();
    }
}

