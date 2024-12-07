//Abstract Product
class Fly {
    public:
      virtual void fly() = 0;
};

class Sound {
    public:
      virtual void sound() = 0;
};

//Abstract Factory
class BirdFactory {
    public:
      virtual Fly* createFly() = 0;
      virtual Sound* createSound() = 0;
};