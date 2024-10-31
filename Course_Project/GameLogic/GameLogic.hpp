#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "../Board/Board.hpp"
#include "../Player/Player.hpp"

class GameLogic {
    protected:
      Board* board_;
      Player* player_1;
      Player* player_2;
      //Player* currentPlayer;

    public:
      GameLogic(Board* gameBoard, std::string player1_name, std::string player2_name);
      ~GameLogic();
      virtual void Make_move(int column);
      void Switch_Player();
      bool is_Available(int column);
      bool check_Win();
      bool check_Drawgame();
      void Checking();
      int GetTopEmptyRow(int column);
      Player* currentPlayer;
};

#endif //GAMELOGIC_HPP