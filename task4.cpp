#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double height, verticalAcceleration;
    std::cout << "Target height h (m): ";
    std::cin >> height;
    std::cout << "Vertical acceleration ay (m/s^2): ";
    std::cin >> verticalAcceleration;

    if (!std::cin || height <= 0 || verticalAcceleration <= 0) {
        std::cerr << "Error: height and acceleration must be positive.\n";
        return 1;
    }

    const double time = std::sqrt(2.0 * height / verticalAcceleration);
    std::cout << std::fixed << std::setprecision(3)
              << "Climb time t = " << time << " s\n";
}
