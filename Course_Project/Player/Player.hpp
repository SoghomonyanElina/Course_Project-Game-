#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
    private:
      std::string name;
      char symbol;
    public:
      Player(std::string name_, char symbol_) : name(name_), symbol(symbol_) {}
      std::string get_name() const;
      char get_symbol() const;
};

#endif //PLAYER_HPP