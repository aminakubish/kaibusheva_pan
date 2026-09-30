#include <iomanip>
#include <iostream>

int main() {
    double area, velocity, density, liftCoefficient;
    std::cout << "Wing area S (m^2): ";
    std::cin >> area;
    std::cout << "Velocity V (m/s): ";
    std::cin >> velocity;
    std::cout << "Air density rho (kg/m^3): ";
    std::cin >> density;
    std::cout << "Lift coefficient CL: ";
    std::cin >> liftCoefficient;

    if (!std::cin || area <= 0 || velocity < 0 || density <= 0 || liftCoefficient < 0) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    const double lift = 0.5 * density * velocity * velocity * area * liftCoefficient;
    std::cout << std::fixed << std::setprecision(2)
              << "Lift force L = " << lift << " N\n";
}
