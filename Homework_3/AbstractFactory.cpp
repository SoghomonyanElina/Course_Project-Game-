#include <iostream>
#include "Abstraction.hpp"

//Concrete Product
class CranesFly : public Fly {
    public:
      void fly() override {
        std::cout << "Crane's Fly" << std::endl;
    }
};

class CranesSound : public Sound {
    public:
      void sound() override {
        std::cout << "Crane's Sound" << std::endl;
      }
};

class DovesFly : public Fly {
    public:
      void fly() override {
        std::cout << "Dove's fly" << std::endl;
      }
};

class DovesSound : public Sound {
    public:
      void sound() override {
        std::cout << "Dove's sound" << std::endl;
      }
};

//Concrete Factory
class DoveFactory : public BirdFactory {
    public:
      Fly* createFly() override {
        return new DovesFly();
      }
      Sound* createSound() override {
        return new DovesSound();
      } 
};

class CraneFactory : public BirdFactory {
    public:
      Fly* createFly() override {
        return new CranesFly();
      }
      Sound* createSound() override {
        return new CranesSound();
      }
};


//Client Code
void ClientCode(BirdFactory* factory) {
    Fly* fly_ = factory->createFly();
    Sound* sound_ = factory->createSound();
    fly_->fly();
    sound_->sound();
    delete fly_;
    delete sound_;
}

int main() {
    BirdFactory* factory = new CraneFactory();
    ClientCode(factory);
    delete factory;
    factory = new DoveFactory();
    ClientCode(factory);
    delete factory;
}






