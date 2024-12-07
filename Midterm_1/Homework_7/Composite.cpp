#include <iostream>
#include <vector>

//Component
class GameObject {
    public:
      virtual void draw() const = 0;
      virtual ~GameObject() = default;
};

//Leaf
class Wall : public GameObject {
    public:
      void draw() const override {
        std::cout << "Drawing a wall" << std::endl;
      }
};

class Enemy : public GameObject {
    public:
      void draw() const override {
        std::cout << "Drawing an enemy" << std::endl;
      }
};

class Weapon : public GameObject {
    public:
      void draw() const override {
        std::cout << "Drawing a weapon" << std::endl;
      }
};

//Compoiste
class Room : public GameObject {
    private:
      std::vector<GameObject*> objects;
    public:
      void AddObjects(GameObject* obj) {
        objects.push_back(obj);
      }
      void draw() const override {
        std::cout << "Drawing a room consists:" << std::endl;
        for(auto& ob : objects) {
            ob->draw();
        }
      }
      ~Room() {
        for(auto& ob : objects) {
            delete ob;
        }
      }
};

int main() {
    Room* room = new Room();
    room->AddObjects(new Wall);
    room->AddObjects(new Enemy);
    room->AddObjects(new Weapon);
    room->draw();
    delete room;
}