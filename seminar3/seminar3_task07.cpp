#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    constexpr double v0 = 50.0;
    constexpr double g = 9.8;
    constexpr double dt = 1.0;
    std::vector<double> times;
    std::vector<double> heights;

    for (double t = 0.0; t <= 20.0; t += dt) {
        times.push_back(t);
        heights.push_back(v0 * t - 0.5 * g * t * t);
    }

    const auto firstNonPositive = std::find_if(
        heights.begin(), heights.end(), [](double h) { return h <= 0.0; });

    if (firstNonPositive == heights.end()) {
        std::cout << "В заданном диапазоне высота не стала неположительной.\n";
        return 0;
    }

    const auto index = static_cast<std::size_t>(
        std::distance(heights.begin(), firstNonPositive));
    std::cout << std::fixed << std::setprecision(2)
              << "Первое значение h <= 0 найдено при t = " << times[index]
              << " с, h = " << heights[index] << " м.\n";

    const auto fallAfterLaunch = std::find_if(
        heights.begin() + 1, heights.end(), [](double h) { return h <= 0.0; });
    if (fallAfterLaunch != heights.end()) {
        const auto fallIndex = static_cast<std::size_t>(
            std::distance(heights.begin(), fallAfterLaunch));
        std::cout << "После старта ракета впервые достигла земли при t = "
                  << times[fallIndex] << " с, h = " << heights[fallIndex] << " м.\n";
    }
}
