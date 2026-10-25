#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    constexpr double v0 = 50.0;
    constexpr double g = 9.8;
    constexpr double dt = 0.5;
    std::vector<double> times;
    std::vector<double> heights;

    for (double t = 0.0;; t += dt) {
        const double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0)
            break;
        times.push_back(t);
        heights.push_back(h);
    }

    const auto maximum = std::max_element(heights.begin(), heights.end());
    const auto index = static_cast<std::size_t>(
        std::distance(heights.begin(), maximum));

    std::cout << std::fixed << std::setprecision(2)
              << "Максимальная высота ракеты: " << *maximum << " м.\n"
              << "Время достижения максимума: " << times[index] << " с.\n";
}
