#include <iomanip>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    constexpr double vx = 30.0;
    constexpr double vy = 20.0;
    constexpr double vz = 40.0;
    constexpr double dt = 1.0;
    constexpr double tMax = 10.0;

    std::vector<double> times;
    std::vector<std::vector<double>> trajectory;

    for (double t = 0.0; t <= tMax; t += dt) {
        times.push_back(t);
        trajectory.push_back({vx * t, vy * t, vz * t});
    }

    std::cout << "Траектория ракеты в трехмерном пространстве:\n";
    std::cout << std::setw(10) << "t, с" << std::setw(12) << "x, м"
              << std::setw(12) << "y, м" << std::setw(12) << "z, м\n";
    std::cout << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < trajectory.size(); ++i) {
        std::cout << std::setw(10) << times[i]
                  << std::setw(12) << trajectory[i][0]
                  << std::setw(12) << trajectory[i][1]
                  << std::setw(12) << trajectory[i][2] << '\n';
    }
}
