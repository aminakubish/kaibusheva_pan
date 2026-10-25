#include <iomanip>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    constexpr double v0 = 50.0;
    constexpr double g = 9.8;
    constexpr double dt = 1.0;

    if (v0 <= 0) {
        std::cout << "Начальная скорость должна быть больше нуля.\n";
        return 0;
    }

    std::vector<double> times;
    std::vector<double> heights;
    const auto expectedSize = static_cast<std::size_t>(v0 * 2.0 / g / dt + 2.0);
    times.reserve(expectedSize);
    heights.reserve(expectedSize);

    for (double t = 0.0; t <= 1000.0; t += dt) {
        const double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0)
            break;
        times.push_back(t);
        heights.push_back(h);
    }

    std::cout << "Траектория ракеты при v0 = " << v0 << " м/с:\n";
    std::cout << "Время (с) | Высота (м)\n";
    std::cout << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < times.size(); ++i)
        std::cout << std::setw(9) << times[i] << " | " << std::setw(10) << heights[i] << '\n';
}
