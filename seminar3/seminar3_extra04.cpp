#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    const std::vector<double> coordinates = {0.0, 12.0, 27.0, 20.0, 38.0, 55.0, 48.0};
    std::vector<double> displacements(coordinates.size());
    std::adjacent_difference(
        coordinates.begin(), coordinates.end(), displacements.begin());
    if (!displacements.empty())
        displacements.front() = 0.0;

    const double totalDistance = std::accumulate(
        displacements.begin(), displacements.end(), 0.0,
        [](double sum, double displacement) {
            return sum + std::abs(displacement);
        });

    std::cout << std::fixed << std::setprecision(2)
              << "Последовательные смещения ракеты: ";
    for (double displacement : displacements)
        std::cout << displacement << " м ";
    std::cout << "\nСуммарный пройденный путь: " << totalDistance << " м.\n";
}
