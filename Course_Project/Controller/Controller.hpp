#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "../GameLogic/PlayervsPlayer.hpp"
#include "../GameLogic/PlayervsRobot.hpp"
#include "../Menu/Menu.hpp"

class Controller {
    private:
        Board* _board;
        GameLogic* _gamelogic;
    public:
        Controller();
        ~Controller();
        void Start_Game();
        Menu* _menu;
};

#endif //CONTROLLER_HPP
