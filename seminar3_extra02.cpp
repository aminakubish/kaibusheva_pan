#include <algorithm>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    const std::vector<double> sensorReadings = {
        1.2, 0.0, -0.5, 0.0, 2.1, 0.0, 0.0, 3.4, -1.1, 0.0
    };
    const auto zeroCount = std::count(
        sensorReadings.begin(), sensorReadings.end(), 0.0);

    std::cout << "Всего измерений датчика: " << sensorReadings.size() << ".\n"
              << "Количество нулевых показаний: " << zeroCount << ".\n";
}
