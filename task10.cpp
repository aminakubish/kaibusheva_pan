#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

int main() {
    double mass, drag, height, minThrust, maxThrust, thrustStep;
    std::cout << "Mass m (kg), drag D (N), target height h (m): ";
    std::cin >> mass >> drag >> height;
    std::cout << "Tmin, Tmax, deltaT (N): ";
    std::cin >> minThrust >> maxThrust >> thrustStep;

    if (!std::cin || mass <= 0 || drag < 0 || height <= 0 || minThrust < 0 ||
        maxThrust < minThrust || thrustStep <= 0) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    double bestTime = std::numeric_limits<double>::infinity();
    double bestThrust = 0.0;

    std::cout << std::fixed << std::setprecision(3)
              << "\nThrust (N)\tAcceleration (m/s^2)\tTime (s)\n";
    for (double thrust = minThrust; thrust <= maxThrust + thrustStep * 1e-9; thrust += thrustStep) {
        const double verticalAcceleration = (thrust - drag) / mass;
        std::cout << thrust << "\t\t" << verticalAcceleration << "\t\t";

        if (verticalAcceleration > 0) {
            const double time = std::sqrt(2.0 * height / verticalAcceleration);
            std::cout << time;
            if (time < bestTime) {
                bestTime = time;
                bestThrust = thrust;
            }
        } else {
            std::cout << "not reachable";
        }
        std::cout << '\n';
    }

    if (std::isfinite(bestTime))
        std::cout << "\nOptimal thrust = " << bestThrust
                  << " N, minimum climb time = " << bestTime << " s\n";
    else
        std::cout << "\nNo tested thrust produces positive climb acceleration.\n";
}
