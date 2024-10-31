#ifndef MENU_HPP
#define MENU_HPP
#include <ncurses.h>
#include <string>
#include <utility>

enum GameMode {
    PLAYER_VS_PLAYER,
    PLAYER_VS_ROBOT,
    EXIT
};

class Menu {
    public: 
      Menu() {}
      GameMode Show_Menu();
      std::pair<std::string, std::string> GetPlayerNames();
      GameMode mode; 
};

#endif //MENU_HPP