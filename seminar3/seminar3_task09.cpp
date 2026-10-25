#include <iomanip>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    const std::vector<double> measuredHeights = {
        0.0, 12.0, 19.0, 31.0, 38.0, 52.0, 47.0, 61.0, 58.0, 70.0, 67.0
    };
    std::vector<double> smoothed(measuredHeights.size());

    if (measuredHeights.empty()) {
        std::cout << "Вектор измерений пуст.\n";
        return 0;
    }

    smoothed.front() = measuredHeights.front();
    smoothed.back() = measuredHeights.back();
    for (std::size_t i = 1; i + 1 < measuredHeights.size(); ++i) {
        smoothed[i] = (measuredHeights[i - 1] + measuredHeights[i]
                       + measuredHeights[i + 1]) / 3.0;
    }

    std::cout << "Исходные и сглаженные значения высоты:\n"
              << "Шаг | Исходная высота (м) | Сглаженная высота (м)\n";
    std::cout << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < measuredHeights.size(); ++i) {
        std::cout << std::setw(3) << i << " | " << std::setw(19) << measuredHeights[i]
                  << " | " << std::setw(22) << smoothed[i] << '\n';
    }
}
