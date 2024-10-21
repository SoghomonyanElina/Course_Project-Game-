#include <iostream>
#include <cmath>

class Triangle {
    private:
      Triangle(double area) : area(area) {}
    public:
      double area;
      friend class AreaFactory;
};

class AreaFactory {
    public:
       static Triangle Heron_formula(double side_1, double side_2, double side_3) {
        double semiper = (side_1 + side_2 + side_3) / 2;
        double area = sqrt(semiper * (semiper - side_1) * (semiper - side_2) * (semiper - side_3));
        return Triangle(area);
       }
       static Triangle getArea(double side_1, double side_2, double angle) {
        double angle_radians = angle * M_PI / 180;
        double area =  (side_1 * side_2 * sin(angle_radians)) / 2;
        return Triangle(area);
       }
};

int main() {
    Triangle obj_1 = AreaFactory::Heron_formula(5, 6, 8);
    std::cout << "Square by Heron's formula: " << obj_1.area << std::endl;
    Triangle obj_2 = AreaFactory::getArea(5, 6, 45);
    std::cout << "Square by the usual formula: " << obj_2.area << std::endl;
}