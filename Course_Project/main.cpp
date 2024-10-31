#include "Controller.hpp"

int main() {
    Controller controller;
    if(controller._menu->mode != EXIT) {
        controller.Start_Game();
    }
}
