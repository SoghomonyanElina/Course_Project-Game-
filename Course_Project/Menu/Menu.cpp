#include "Menu.hpp"

GameMode Menu::Show_Menu() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    int highlight = 0;
    const char* choices[] = {"Player VS Player", "Player VS Robot", "Exit"};
    int num_choces = sizeof(choices) / sizeof(choices[0]);
    int choice;
    while(true) {
        clear();
        for(int i = 0; i < num_choces; ++i) {
            if(i == highlight) {
                attron(A_REVERSE);
            }
            mvprintw(i + 1, 60, choices[i]);
            if(i == highlight) {
                attroff(A_REVERSE);
            }
        }
        choice = getch();
        switch(choice) {
            case KEY_UP:
               highlight = (highlight == 0) ? num_choces - 1 : highlight - 1;
               break;
            case KEY_DOWN:
                highlight = (highlight == num_choces - 1) ? 0 : highlight + 1;
                break;
            case 10:
                if(highlight == num_choces - 1) {
                    endwin();
                    return EXIT;
                }
                return static_cast<GameMode>(highlight);
        }
        refresh();
    }
    endwin();
    return EXIT;
}

std::pair<std::string, std::string> Menu::GetPlayerNames() {
    std::string player_1;
    std::string player_2;
    clear();
    initscr();
    echo();
    cbreak();
    char name[50];
    mvprintw(1, 60, "Enter Player_1's name: ");
    getnstr(name, sizeof(name) - 1);
    player_1 = name;
    if(mode == PLAYER_VS_ROBOT) {
        player_2 = "Robot";
    }
    else {
        mvprintw(2, 60, "Enter Player_2's name: ");
        getnstr(name, sizeof(name) - 1);
        player_2 = name;
    }
    endwin();
    return {player_1, player_2};
}

