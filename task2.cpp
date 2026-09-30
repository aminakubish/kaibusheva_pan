#include <iomanip>
#include <iostream>

double calculateDrag(double density, double velocity, double area, double dragCoefficient) {
    return 0.5 * density * velocity * velocity * area * dragCoefficient;
}

int main() {
    double area, velocity, density, dragCoefficient;
    std::cout << "Wing area S (m^2): ";
    std::cin >> area;
    std::cout << "Velocity V (m/s): ";
    std::cin >> velocity;
    std::cout << "Air density rho (kg/m^3): ";
    std::cin >> density;
    std::cout << "Drag coefficient CD: ";
    std::cin >> dragCoefficient;

    if (!std::cin || area <= 0 || velocity < 0 || density <= 0 || dragCoefficient < 0) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2)
              << "Drag force D = "
              << calculateDrag(density, velocity, area, dragCoefficient) << " N\n";
}
