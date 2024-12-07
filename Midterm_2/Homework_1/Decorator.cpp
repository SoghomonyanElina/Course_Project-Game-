#include <iostream>
#include <memory>

class Cake {
    public:
      virtual std::string makeCake() = 0;
      virtual double getCost() = 0;
      virtual ~Cake() = default;
};

class SimpleCake : public Cake {
    public:
      std::string makeCake() override {
        return "Simple cake";
      }
      double getCost() override {
        return 6.0;
      }
};

class Decorator : public Cake {
    protected:
      std::shared_ptr<Cake> cake_;
    public:
      Decorator(std::shared_ptr<Cake> cake) : cake_(std::move(cake)) {}
      std::string makeCake() override {
        return cake_->makeCake();
      }
      double getCost() override {
        return cake_->getCost();
      }
};

class ChocolateDecorator : public Decorator {
  public:
    ChocolateDecorator(std::shared_ptr<Cake> cake) : Decorator(cake) {}
    std::string makeCake() override {
      return cake_->makeCake() + " with chocolate";
    }
    double getCost() override {
      return cake_->getCost() + 3.0;
    }
};

class CreamDecorator : public Decorator {
  public: 
    CreamDecorator(std::shared_ptr<Cake> cake) : Decorator(cake) {}
    std::string makeCake() override {
      return cake_->makeCake() + " with cream";
    }
    double getCost() override {
      return cake_->getCost() + 4.0;
    }
};

class FruitDecorator : public Decorator {
  public:
    FruitDecorator(std::shared_ptr<Cake> cake) : Decorator(cake) {}
    std::string makeCake() override {
      return cake_->makeCake() + " with fruit";
    }
    double getCost() override {
      return cake_->getCost() + 4.0;
    }
};

int main() {
  std::shared_ptr<Cake> simpleCake = std::make_shared<SimpleCake>();
  std::cout << simpleCake->makeCake() << ' ' << simpleCake->getCost() << '$'<< std::endl;

  auto ChocolateCake = std::make_shared<ChocolateDecorator>(std::move(simpleCake));
  std::cout << ChocolateCake->makeCake() << ' ' << ChocolateCake->getCost() << '$' << std::endl;

  auto CreamCake = std::make_shared<CreamDecorator>(std::move(ChocolateCake));
  std::cout << CreamCake->makeCake() << ' ' << CreamCake->getCost() << '$' << std::endl;

  auto cake = std::make_shared<FruitDecorator>(std::move(CreamCake));
  std::cout << cake->makeCake() << ' ' << cake->getCost() << '$' << std::endl;
}