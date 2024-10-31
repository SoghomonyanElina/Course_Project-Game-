#ifndef PLAYERVSPLAYER_HPP
#define PLAYERVSPLAYER_HPP
#include "GameLogic.hpp"

class PlayervsPlayer : public GameLogic {
    public:
        PlayervsPlayer(Board* gameBoard, std::string player1_name, std::string player2_name) 
          : GameLogic(gameBoard, player1_name, player2_name) {}
};

#endif //PLAYERVSPLAYER_HPP