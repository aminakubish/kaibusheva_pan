#include <algorithm>
#include <iomanip>
#include <iostream>
#include <optional>
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
    std::optional<double> timeOfFall;
};

Trajectory simulate(double initialVelocity, double g, double dt, double maximumTime = 1000.0) {
    Trajectory result;
    for (double t = 0.0; t <= maximumTime; t += dt) {
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
    std::optional<double> timeOfFall;
    if (fall != trajectory.heights.end()) {
        const auto fallIndex = static_cast<std::size_t>(
            std::distance(trajectory.heights.begin(), fall));
        timeOfFall = trajectory.times[fallIndex];
    }
    return {*maximum, trajectory.times[maximumIndex], timeOfFall};
}

void printSummary(const std::string& name, const Summary& summary) {
    std::cout << name << ": максимальная высота = " << summary.maximumHeight
              << " м, время максимума = " << summary.timeOfMaximum << " с, ";
    if (summary.timeOfFall)
        std::cout << "время падения = " << *summary.timeOfFall << " с.\n";
    else
        std::cout << "ракета все еще находится в воздухе.\n";
}

int main() {
    setupRussianConsole();

    constexpr double g = 9.8;
    constexpr double dt = 1.0;
    const Summary first = summarize(simulate(50.0, g, dt));
    const Summary second = summarize(simulate(65.0, g, dt));

    std::cout << std::fixed << std::setprecision(2);
    printSummary("Первая ракета", first);
    printSummary("Вторая ракета", second);

    if (first.maximumHeight > second.maximumHeight)
        std::cout << "Выше поднялась первая ракета.\n";
    else if (second.maximumHeight > first.maximumHeight)
        std::cout << "Выше поднялась вторая ракета.\n";
    else
        std::cout << "Ракеты достигли одинаковой высоты.\n";

    if (!first.timeOfFall && second.timeOfFall)
        std::cout << "Дольше в воздухе находилась первая ракета.\n";
    else if (first.timeOfFall && !second.timeOfFall)
        std::cout << "Дольше в воздухе находилась вторая ракета.\n";
    else if (!first.timeOfFall && !second.timeOfFall)
        std::cout << "Обе ракеты все еще находятся в воздухе.\n";
    else if (*first.timeOfFall > *second.timeOfFall)
        std::cout << "Дольше в воздухе находилась первая ракета.\n";
    else if (*second.timeOfFall > *first.timeOfFall)
        std::cout << "Дольше в воздухе находилась вторая ракета.\n";
    else
        std::cout << "Ракеты находились в воздухе одинаковое время.\n";

    // Граничный тест: за 1000 секунд очень быстрая ракета еще не упала.
    const Summary fastRocket = summarize(simulate(6000.0, g, dt, 1000.0));
    std::cout << "Граничный тест для v0 = 6000 м/с: ";
    if (!fastRocket.timeOfFall)
        std::cout << "пройден, ракета все еще в воздухе.\n";
    else
        std::cout << "не пройден.\n";
}
