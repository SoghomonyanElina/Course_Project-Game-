#include "Controller.hpp"

Controller::Controller() {
    _board = new Board();
    _menu = new Menu();
    _menu->mode = _menu->Show_Menu();
    if(_menu->mode == EXIT) {
        return;
    }
    auto _names = _menu->GetPlayerNames();
    if(_menu->mode == PLAYER_VS_ROBOT) {
        _gamelogic = new PlayervsRobot(_board, _names.first, _names.second);
    }
    else {
        _gamelogic = new PlayervsPlayer(_board,_names.first, _names.second);
    }
}

Controller::~Controller() {
    delete _board;
    delete _menu;
    delete _gamelogic;
}

void Controller::Start_Game() {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    _board->Board_print();
    mvprintw(5, 20, "Player_1's turn.");
    refresh();
    while(true) {
        int col;
        if(_gamelogic->currentPlayer->get_name() != "Robot") {
            do {
                col = getch() - '0';
                if(col < 1 || col > _board->column) {
                    mvprintw(5, 20, "Invalid column, try again.");
                    refresh();
                }
            }
            while(col < 1 || col > _board->column);
        }
        _gamelogic->Make_move(col);
        if(_gamelogic->check_Win()) {
            mvprintw(5, 20, "%s wins!", _gamelogic->currentPlayer->get_name().c_str());
            refresh();
            mvprintw(6, 20, "Press any key to exit.");
            getch();
            endwin();
            return;
        } 
        else if(_gamelogic->check_Drawgame()) {
            mvprintw(5, 20, "It's a draw game!");
            refresh();
            mvprintw(6, 20, "Press any key to exit.");
            getch();
            endwin();
            return;
        }
    }
    getch();
    endwin();
    return;
}