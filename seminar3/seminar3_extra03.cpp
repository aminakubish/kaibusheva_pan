#include <algorithm>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    std::vector<double> temperatures = {
        75.0, 82.5, -150.0, 90.0, 215.0, 105.0, -99.0, 180.0, 300.0
    };

    std::cout << "Исходное количество показаний: " << temperatures.size() << ".\n";
    const auto newEnd = std::remove_if(
        temperatures.begin(), temperatures.end(),
        [](double value) { return value < -100.0 || value > 200.0; });
    temperatures.erase(newEnd, temperatures.end());

    std::cout << "Корректные значения температуры двигателя:\n";
    for (double temperature : temperatures)
        std::cout << temperature << " °C\n";
}
