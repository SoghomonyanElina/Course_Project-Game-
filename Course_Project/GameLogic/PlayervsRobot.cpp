#include "PlayervsRobot.hpp"
#include <ncurses.h>

PlayervsRobot::PlayervsRobot(Board* gameBoard, std::string player1_name, std::string player2_name)
                : GameLogic(gameBoard, player1_name, player2_name)
{
    srand(static_cast<unsigned int>(time(0)));
}
              
int PlayervsRobot::Robot_steps() {
    return (rand() % board_->column) + 1;
}

void PlayervsRobot::Make_move(int column) {
    if(currentPlayer == player_1) {
        GameLogic::Make_move(column);
    }
    else {
        mvprintw(5, 20, "Robot's turn.");
        refresh();
        napms(1300);
        int step = Robot_steps();
        GameLogic::Make_move(step);
    }
}