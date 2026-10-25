#include <algorithm>
#include <cmath>
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
    const auto pointCount = static_cast<std::size_t>(tMax / dt) + 1;
    times.reserve(pointCount);
    trajectory.reserve(pointCount);

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    double maximumCheckError = 0.0;

    for (double t = 0.0; t <= tMax; t += dt) {
        times.push_back(t);
        trajectory.push_back({x, y, z});
        maximumCheckError = std::max(maximumCheckError, std::abs(x - vx * t));

        // Пошаговое обновление координат из условия.
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
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
    std::cout << "Проверка x = vx * t: максимальная ошибка = "
              << maximumCheckError << " м.\n";
}
