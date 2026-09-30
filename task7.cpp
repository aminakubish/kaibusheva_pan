#include <iomanip>
#include <iostream>

int main() {
    constexpr double g = 9.81;
    double mass, thrust, lift, drag;
    std::cout << "Mass m (kg), thrust T (N), lift L (N), drag D (N): ";
    std::cin >> mass >> thrust >> lift >> drag;

    if (!std::cin || mass <= 0 || thrust < 0 || lift < 0 || drag < 0) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    const double acceleration = (thrust - drag) / mass;
    const double verticalAcceleration = (lift - mass * g) / mass;

    const char* mode;
    if (acceleration > 0.5)
        mode = "climb";
    else if (acceleration >= 0.0)
        mode = "level flight";
    else
        mode = "descent";

    std::cout << std::fixed << std::setprecision(3)
              << "Longitudinal acceleration = " << acceleration << " m/s^2\n"
              << "Vertical acceleration = " << verticalAcceleration << " m/s^2\n"
              << "Selected flight mode: " << mode << '\n';
}
