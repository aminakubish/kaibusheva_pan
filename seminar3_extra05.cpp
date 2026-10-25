#include <algorithm>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

int main() {
    setupRussianConsole();

    std::vector<double> xCoordinates = {
        15.0, 3.0, 8.0, 15.0, -2.0, 8.0, 4.0, 3.0, 20.0, -2.0
    };

    std::sort(xCoordinates.begin(), xCoordinates.end());
    const auto newEnd = std::unique(xCoordinates.begin(), xCoordinates.end());
    xCoordinates.erase(newEnd, xCoordinates.end());

    std::cout << "Отсортированные координаты без дубликатов:\n";
    for (double coordinate : xCoordinates)
        std::cout << coordinate << " ";
    std::cout << '\n';
}
