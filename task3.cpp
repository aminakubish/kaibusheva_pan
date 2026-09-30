#include <iomanip>
#include <iostream>

int main() {
    constexpr double g = 9.81;
    double mass, lift, drag, thrust;
    std::cout << "Mass m (kg): ";
    std::cin >> mass;
    std::cout << "Lift L (N): ";
    std::cin >> lift;
    std::cout << "Drag D (N): ";
    std::cin >> drag;
    std::cout << "Thrust T (N): ";
    std::cin >> thrust;

    if (!std::cin || mass <= 0 || lift < 0 || drag < 0 || thrust < 0) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    const double longitudinalAcceleration = (thrust - drag) / mass;
    const double verticalAcceleration = (lift - mass * g) / mass;

    std::cout << std::fixed << std::setprecision(3)
              << "Longitudinal acceleration ax = " << longitudinalAcceleration << " m/s^2\n"
              << "Vertical acceleration ay = " << verticalAcceleration << " m/s^2\n";
}
