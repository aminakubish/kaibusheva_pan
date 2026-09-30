#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct Aircraft {
    std::string name;
    double mass;
    double thrust;
    double liftCoefficient;
    double dragCoefficient;
    double climbTime = std::numeric_limits<double>::infinity();
};

int main() {
    constexpr double g = 9.81;
    int count;
    double density, velocity, wingArea, height;
    std::cout << "Number of aircraft: ";
    std::cin >> count;
    std::cout << "Common rho, velocity, wing area, target height: ";
    std::cin >> density >> velocity >> wingArea >> height;

    if (!std::cin || count <= 0 || density <= 0 || velocity < 0 || wingArea <= 0 || height <= 0) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    std::vector<Aircraft> aircraft(count);
    for (int i = 0; i < count; ++i) {
        aircraft[i].name = "Aircraft " + std::to_string(i + 1);
        std::cout << aircraft[i].name << " - mass, thrust, CL, CD: ";
        std::cin >> aircraft[i].mass >> aircraft[i].thrust
                 >> aircraft[i].liftCoefficient >> aircraft[i].dragCoefficient;
        if (!std::cin || aircraft[i].mass <= 0 || aircraft[i].thrust < 0 ||
            aircraft[i].liftCoefficient < 0 || aircraft[i].dragCoefficient < 0) {
            std::cerr << "Error: invalid aircraft parameters.\n";
            return 1;
        }

        const double lift = 0.5 * density * velocity * velocity * wingArea
                            * aircraft[i].liftCoefficient;
        const double ay = (lift - aircraft[i].mass * g) / aircraft[i].mass;
        if (ay > 0)
            aircraft[i].climbTime = std::sqrt(2.0 * height / ay);
    }

    std::sort(aircraft.begin(), aircraft.end(), [](const Aircraft& a, const Aircraft& b) {
        return a.climbTime < b.climbTime;
    });

    std::cout << std::fixed << std::setprecision(3) << "\nSorted by climb time:\n";
    for (const auto& plane : aircraft) {
        std::cout << plane.name << ": ";
        if (std::isfinite(plane.climbTime))
            std::cout << plane.climbTime << " s\n";
        else
            std::cout << "cannot climb with the supplied parameters\n";
    }
}
