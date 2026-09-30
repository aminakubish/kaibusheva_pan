#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct Aircraft {
    double mass;
    double wingArea;
    double thrust;
    double liftCoefficient;
    double dragCoefficient;
};

int main() {
    int count;
    double density, velocity;
    std::cout << "Number of aircraft N: ";
    std::cin >> count;
    std::cout << "Air density rho (kg/m^3) and velocity V (m/s): ";
    std::cin >> density >> velocity;

    if (!std::cin || count <= 0 || density <= 0 || velocity < 0) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    std::vector<Aircraft> aircraft(count);
    double bestAcceleration = -std::numeric_limits<double>::infinity();
    int leader = -1;

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < count; ++i) {
        std::cout << "Aircraft " << i + 1 << " - mass, wing area, thrust, CL, CD: ";
        std::cin >> aircraft[i].mass >> aircraft[i].wingArea >> aircraft[i].thrust
                 >> aircraft[i].liftCoefficient >> aircraft[i].dragCoefficient;

        const auto& plane = aircraft[i];
        if (!std::cin || plane.mass <= 0 || plane.wingArea <= 0 || plane.thrust < 0 ||
            plane.liftCoefficient < 0 || plane.dragCoefficient < 0) {
            std::cerr << "Error: invalid aircraft parameters.\n";
            return 1;
        }

        const double dynamicPressure = 0.5 * density * velocity * velocity;
        const double lift = dynamicPressure * plane.wingArea * plane.liftCoefficient;
        const double drag = dynamicPressure * plane.wingArea * plane.dragCoefficient;
        const double acceleration = (plane.thrust - drag) / plane.mass;

        std::cout << "  L=" << lift << " N, D=" << drag
                  << " N, acceleration=" << acceleration << " m/s^2\n";
        if (acceleration > bestAcceleration) {
            bestAcceleration = acceleration;
            leader = i;
        }
    }

    std::cout << "Greatest acceleration: Aircraft " << leader + 1
              << " (" << bestAcceleration << " m/s^2)\n";
}
