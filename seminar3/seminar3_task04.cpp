#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    constexpr double v0 = 50.0;
    constexpr double g = 9.8;
    constexpr double dt = 1.0;
    constexpr double tMax = 10.0;
    std::vector<double> velocities;

    for (double t = 0.0; t <= tMax; t += dt)
        velocities.push_back(v0 - g * t);

    if (velocities.empty()) {
        std::cout << "Вектор скоростей пуст.\n";
        return 0;
    }

    const double sum = std::accumulate(velocities.begin(), velocities.end(), 0.0);
    const double average = sum / static_cast<double>(velocities.size());

    std::cout << std::fixed << std::setprecision(2)
              << "Количество измерений скорости: " << velocities.size() << ".\n"
              << "Средняя скорость по измерениям: " << average << " м/с.\n";
}
