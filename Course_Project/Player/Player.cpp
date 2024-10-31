#include <iostream>
#include "Player.hpp"

std::string Player::get_name() const {
    return name;
}

char Player::get_symbol() const {
    return symbol;
}