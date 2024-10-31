#ifndef PLAYERVSROBOT_HPP
#define PLAYERVSROBOT_HPP
#include "GameLogic.hpp"
#include <cstdlib>
#include <ctime>

class PlayervsRobot : public GameLogic {
    private:
      int Robot_steps();
    public:
      PlayervsRobot(Board* gameBoard, std::string player1_name, std::string player2_name);
      void Make_move(int column) override;
};

#endif //PLAYERVSROBOT_HPP