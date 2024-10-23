#include <iostream>

//Product
class Cake {
    private:
      std::string base;
      std::string layers;
      std::string cream;
    public:
      void setBase(const std::string base) {
        this->base = base;
      }
      void setLayers(const std::string layers) {
        this->layers = layers;
      }
      void setCream(const std::string cream) {
        this->cream = cream;
      }
      void showIngredients() {
        std::cout << "Base: "   << this->base << std::endl;
        std::cout << "Layers: " << this->layers << std::endl;
        std::cout << "Cream: "  << this->cream << std::endl;
      }
};

//Product Builder
class CakeBuilder {
    public:
      virtual void buildBase() = 0;
      virtual void buildLayers() = 0;
      virtual void buildCream() = 0;
      virtual Cake* getCake() = 0;
};

//Concrete Product Builder
class VanillaCakeBuilder : public CakeBuilder {
    private:
      Cake* cake;
    public:
      VanillaCakeBuilder() {
        cake = new Cake();
      }
      void buildBase() override {
        cake->setBase("Vanilla base");
      }
      void buildLayers() override {
        cake->setLayers("3");
      }
      void buildCream() override {
        cake->setCream("Vanilla cream");
      }
      Cake* getCake() override {
        return cake;
      }
      ~VanillaCakeBuilder() {
        delete cake;
      }
};

class ChocolateCakeBuilder : public CakeBuilder {
    private:
      Cake* cake;
    public:
      ChocolateCakeBuilder() {
        cake = new Cake;
      }
      void buildBase() override {
        cake->setBase("Chocolate base");
      }
      void buildLayers() override {
        cake->setLayers("2");
      }
      void buildCream() override {
        cake->setCream("Chocolate cream");
      }
      Cake* getCake() override {
        return cake;
      }
      ~ChocolateCakeBuilder() {
        delete cake;
      }
};

//Director
class CakeDirector {
    private:
      CakeBuilder* builder;
    public:
      void setBuilder(CakeBuilder* builder) {
        this->builder = builder;
      }
      void constructCake() {
        builder->buildBase();
        builder->buildLayers();
        builder->buildCream();
      }
};

int main() {
    Cake* cake;
    CakeDirector director;
    ChocolateCakeBuilder builder;
    director.setBuilder(&builder);
    director.constructCake();
    cake = builder.getCake();
    cake->showIngredients();
    /*VanillaCakeBuilder builder_;
    director.setBuilder(&builder_);
    director.constructCake();
    cake = builder_.getCake();
    cake->showIngredients();*/
}

