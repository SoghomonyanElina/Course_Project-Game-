#include <iostream>
#include <memory>

class State {
  public:
    virtual void handleRequest() = 0;
    virtual ~State() = default;
};

class CoffeeMachine {
  private:
    std::unique_ptr<State> state;
  public:
    CoffeeMachine(std::unique_ptr<State> initialState) : state(std::move(initialState)) {}
    void setState(std::unique_ptr<State> newState) {
        state = std::move(newState);
    }
    void pressButton() {
        state->handleRequest();
    }
};

class ReadyState : public State {
  public:
    void handleRequest() override {
        std::cout << "The machine is ready. Click to order coffee or tea." << std::endl;
    }
};

class BrewingCoffeeState : public State {
  public:
    void handleRequest() override {
        std::cout << "The coffee is being made." << std::endl;
    }
};

class BrewingTeaState : public State {
  public:
    void handleRequest() override {
        std::cout << "The tea is being made." << std::endl;
    }
};

int main() {
    CoffeeMachine coffeeMachine(std::make_unique<ReadyState>());
    coffeeMachine.pressButton();
    std::cout << "Press for coffee." << std::endl;
    coffeeMachine.setState(std::make_unique<BrewingCoffeeState>());
    coffeeMachine.pressButton();
    coffeeMachine.setState(std::make_unique<ReadyState>());
    coffeeMachine.pressButton();
    std::cout << "Press for tea." << std::endl;
    coffeeMachine.setState(std::make_unique<BrewingTeaState>());
    coffeeMachine.pressButton();
}











