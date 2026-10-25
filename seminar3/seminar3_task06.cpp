#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

void removeHeightsBelowTen(std::vector<double>& heights) {
    const auto newEnd = std::remove_if(heights.begin(), heights.end(),
                                       [](double h) { return h < 10.0; });
    heights.erase(newEnd, heights.end());
}

int main() {
    setupRussianConsole();

    constexpr double v0 = 50.0;
    constexpr double g = 9.8;
    constexpr double dt = 1.0;
    std::vector<double> heights;

    for (double t = 0.0;; t += dt) {
        const double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0)
            break;
        heights.push_back(h);
    }

    std::cout << "Исходное количество значений: " << heights.size() << ".\n";
    removeHeightsBelowTen(heights);

    std::cout << "Высоты не ниже 10 м:\n" << std::fixed << std::setprecision(2);
    if (heights.empty()) {
        std::cout << "Подходящих значений нет.\n";
    } else {
        for (double h : heights)
            std::cout << h << " м\n";
    }

    std::vector<double> allRemoved = {0.0, 5.0, 9.99};
    removeHeightsBelowTen(allRemoved);
    const bool allRemovedTest = allRemoved.empty();

    std::vector<double> nothingRemoved = {10.0, 15.0, 100.0};
    const auto original = nothingRemoved;
    removeHeightsBelowTen(nothingRemoved);
    const bool nothingRemovedTest = nothingRemoved == original;

    std::cout << "Тест «все значения ниже 10»: "
              << (allRemovedTest ? "пройден" : "не пройден") << ".\n"
              << "Тест «ничего не удаляется»: "
              << (nothingRemovedTest ? "пройден" : "не пройден") << ".\n";
}
