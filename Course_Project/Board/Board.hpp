#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>

class Board {
    public:
      static const int row = 6;      
      static const int column = 7;
      int size = row * column;
      char board[row][column];
      Board();
      void Board_print();
      void Board_reset();
      void Set_piece(int row, int column, char symbol);
      bool checkHorizontalWin();
      bool checkVerticalWin();
      bool checkDiagonalWin();
};

#endif //BOARD_HPP

