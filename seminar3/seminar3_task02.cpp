#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

std::size_t findFirstMaximumIndex(const std::vector<double>& values) {
    std::size_t indexMaximum = 0;
    for (std::size_t i = 1; i < values.size(); ++i) {
        if (values[i] > values[indexMaximum])
            indexMaximum = i;
    }
    return indexMaximum;
}

int main() {
    setupRussianConsole();

    constexpr double v0 = 50.0;
    constexpr double g = 9.8;
    constexpr double dt = 1.0;
    std::vector<double> times;
    std::vector<double> heights;

    for (double t = 0.0;; t += dt) {
        const double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0)
            break;
        times.push_back(t);
        heights.push_back(h);
    }

    if (heights.empty()) {
        std::cout << "Данных о высоте нет.\n";
        return 0;
    }

    // Основной способ из условия: ручной цикл с индексом максимума.
    const std::size_t index = findFirstMaximumIndex(heights);

    // Дополнительная проверка тем же алгоритмом STL.
    const auto stlMaximum = std::max_element(heights.begin(), heights.end());
    const auto stlIndex = static_cast<std::size_t>(
        std::distance(heights.begin(), stlMaximum));

    const std::vector<double> plateau = {10.0, 20.0, 20.0, 15.0};
    const bool plateauTestPassed = findFirstMaximumIndex(plateau) == 1;

    std::cout << std::fixed << std::setprecision(2)
              << "Максимальная высота ракеты: " << heights[index] << " м.\n"
              << "Она достигнута в момент времени: " << times[index] << " с.\n"
              << "Проверка через std::max_element: индекс " << stlIndex << ".\n"
              << "Тест с двумя равными максимумами: "
              << (plateauTestPassed ? "пройден" : "не пройден") << ".\n";
}
