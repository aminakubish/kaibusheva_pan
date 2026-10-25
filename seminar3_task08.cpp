#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "seminar3_console_utf8.h"

struct Trajectory {
    std::vector<double> times;
    std::vector<double> heights;
};

struct Summary {
    double maximumHeight;
    double timeOfMaximum;
    double timeOfFall;
};

Trajectory simulate(double initialVelocity, double g, double dt) {
    Trajectory result;
    for (double t = 0.0; t <= 1000.0; t += dt) {
        const double h = initialVelocity * t - 0.5 * g * t * t;
        result.times.push_back(t);
        result.heights.push_back(h);
        if (t > 0.0 && h <= 0.0)
            break;
    }
    return result;
}

Summary summarize(const Trajectory& trajectory) {
    const auto maximum = std::max_element(
        trajectory.heights.begin(), trajectory.heights.end());
    const auto maximumIndex = static_cast<std::size_t>(
        std::distance(trajectory.heights.begin(), maximum));
    const auto fall = std::find_if(
        trajectory.heights.begin() + 1, trajectory.heights.end(),
        [](double h) { return h <= 0.0; });
    const auto fallIndex = static_cast<std::size_t>(
        std::distance(trajectory.heights.begin(), fall));
    return {*maximum, trajectory.times[maximumIndex], trajectory.times[fallIndex]};
}

int main() {
    setupRussianConsole();

    constexpr double g = 9.8;
    constexpr double dt = 1.0;
    const Summary first = summarize(simulate(50.0, g, dt));
    const Summary second = summarize(simulate(65.0, g, dt));

    std::cout << std::fixed << std::setprecision(2)
              << "Ракета   Макс. высота   Время максимума   Время падения\n"
              << "Первая   " << std::setw(12) << first.maximumHeight
              << std::setw(18) << first.timeOfMaximum
              << std::setw(17) << first.timeOfFall << '\n'
              << "Вторая   " << std::setw(12) << second.maximumHeight
              << std::setw(18) << second.timeOfMaximum
              << std::setw(17) << second.timeOfFall << '\n';

    if (first.maximumHeight > second.maximumHeight)
        std::cout << "Выше поднялась первая ракета.\n";
    else if (second.maximumHeight > first.maximumHeight)
        std::cout << "Выше поднялась вторая ракета.\n";
    else
        std::cout << "Ракеты достигли одинаковой высоты.\n";

    if (first.timeOfFall > second.timeOfFall)
        std::cout << "Дольше в воздухе находилась первая ракета.\n";
    else if (second.timeOfFall > first.timeOfFall)
        std::cout << "Дольше в воздухе находилась вторая ракета.\n";
    else
        std::cout << "Ракеты находились в воздухе одинаковое время.\n";
}
