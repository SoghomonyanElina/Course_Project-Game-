#include <iostream>

class Lens {
    public:
      virtual void description() const = 0;
      virtual ~Lens() = default;
};

class PolarizedLens : public Lens {
    public:
      void description() const override {
        std::cout << "Polarized lens" << std::endl;
      }
};

class AntiReflectiveLens : public Lens {
    public:
      void description() const override {
        std::cout << "Antireflective lens" << std::endl; 
      }
};

class TintedLens : public Lens {
    public:
      void description() const override {
        std::cout << "Tinted lens" << std::endl;
      }
};

//Abstraction
class Glasses {
    protected:
       Lens& lens_;
    public:
      Glasses(Lens& lens) : lens_(lens) {}
      virtual void describe() const = 0;
      virtual ~Glasses() = default;
};

class SunGlasses : public Glasses {
    public:
      SunGlasses(Lens& lens) : Glasses(lens) {}
      void describe() const override {
        std::cout << "Sunglasses with ";
        lens_.description();
      }
};

class OpticalGlasses : public Glasses {
    public:
      OpticalGlasses(Lens& lens) : Glasses(lens) {}
      void describe() const override {
        std::cout << "Optical glasses with ";
        lens_.description();
      }
};

class SportsGlasses : public Glasses {
    public:
      SportsGlasses(Lens& lens) : Glasses(lens) {}
      void describe() const override {
        std::cout << "Sports Glasses with ";
        lens_.description();
      }
};

int main() {
    PolarizedLens polar_lens;
    AntiReflectiveLens anti_lens;
    TintedLens tint_lens;

    SunGlasses sun_glasses(polar_lens);
    OpticalGlasses opt_glasses(anti_lens);
    SportsGlasses sport_glasses(tint_lens);

    sun_glasses.describe();
    opt_glasses.describe();
    sport_glasses.describe();
}

