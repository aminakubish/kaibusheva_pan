#include <iomanip>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    constexpr double v0 = 50.0;
    constexpr double g = 9.8;
    constexpr double dt = 1.0;
    constexpr double tMax = 10.0;
    std::vector<double> times;
    std::vector<double> velocities;

    for (double t = 0.0; t <= tMax; t += dt) {
        times.push_back(t);
        velocities.push_back(v0 - g * t);
    }

    std::cout << "Скорость ракеты по шагам времени:\n";
    std::cout << "Время (с) | Скорость (м/с)\n";
    std::cout << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < times.size(); ++i)
        std::cout << std::setw(9) << times[i] << " | " << std::setw(14) << velocities[i] << '\n';

    std::cout << "Точный момент смены знака скорости: " << v0 / g << " с.\n";
}
