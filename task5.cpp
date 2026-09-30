#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct Aircraft {
    std::string name;
    double mass;
    double wingArea;
    double thrust;
    double liftCoefficient;
    double dragCoefficient;
};

int main() {
    constexpr double g = 9.81;
    double density, velocity, height;
    std::cout << "Air density rho (kg/m^3), velocity V (m/s), target height h (m): ";
    std::cin >> density >> velocity >> height;

    std::vector<Aircraft> aircraft(3);
    for (int i = 0; i < 3; ++i) {
        aircraft[i].name = "Aircraft " + std::to_string(i + 1);
        std::cout << aircraft[i].name << " - mass, wing area, thrust, CL, CD: ";
        std::cin >> aircraft[i].mass >> aircraft[i].wingArea >> aircraft[i].thrust
                 >> aircraft[i].liftCoefficient >> aircraft[i].dragCoefficient;
    }

    if (!std::cin || density <= 0 || velocity < 0 || height <= 0) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    double bestTime = std::numeric_limits<double>::infinity();
    std::string bestName = "none";
    std::cout << std::fixed << std::setprecision(2);

    for (const auto& plane : aircraft) {
        if (plane.mass <= 0 || plane.wingArea <= 0 || plane.thrust < 0 ||
            plane.liftCoefficient < 0 || plane.dragCoefficient < 0) {
            std::cerr << "Error: invalid aircraft parameters.\n";
            return 1;
        }

        const double dynamicPressure = 0.5 * density * velocity * velocity;
        const double lift = dynamicPressure * plane.wingArea * plane.liftCoefficient;
        const double drag = dynamicPressure * plane.wingArea * plane.dragCoefficient;
        const double ax = (plane.thrust - drag) / plane.mass;
        const double ay = (lift - plane.mass * g) / plane.mass;

        std::cout << plane.name << ": L=" << lift << " N, D=" << drag
                  << " N, ax=" << ax << " m/s^2, ay=" << ay << " m/s^2";
        if (ay > 0) {
            const double time = std::sqrt(2.0 * height / ay);
            std::cout << ", climb time=" << time << " s";
            if (time < bestTime) {
                bestTime = time;
                bestName = plane.name;
            }
        } else {
            std::cout << ", target height cannot be reached in this model";
        }
        std::cout << '\n';
    }

    if (bestName != "none")
        std::cout << "Fastest climb: " << bestName << " (" << bestTime << " s)\n";
    else
        std::cout << "None of the aircraft can climb with the supplied parameters.\n";
}
