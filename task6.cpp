#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int count;
    double wingArea, liftCoefficient;
    std::cout << "Number of trajectory points: ";
    std::cin >> count;
    std::cout << "Wing area S (m^2) and lift coefficient CL: ";
    std::cin >> wingArea >> liftCoefficient;

    if (!std::cin || count <= 0 || wingArea <= 0 || liftCoefficient < 0) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    std::vector<double> velocities(count), densities(count);
    for (int i = 0; i < count; ++i) {
        std::cout << "Point " << i + 1 << " - velocity (m/s), density (kg/m^3): ";
        std::cin >> velocities[i] >> densities[i];
        if (!std::cin || velocities[i] < 0 || densities[i] <= 0) {
            std::cerr << "Error: invalid trajectory data.\n";
            return 1;
        }
    }

    std::cout << std::fixed << std::setprecision(2)
              << "\nStep\tVelocity\tDensity\tLift\n";
    for (int i = 0; i < count; ++i) {
        const double lift = 0.5 * densities[i] * velocities[i] * velocities[i]
                            * wingArea * liftCoefficient;
        std::cout << i + 1 << '\t' << velocities[i] << "\t\t" << densities[i]
                  << "\t\t" << lift << " N\n";
    }
}
