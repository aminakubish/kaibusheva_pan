#include <cmath>
#include <iomanip>
#include <iostream>
#include "console_utf8.h"

int main() {
    setupRussianConsole();
    double height, verticalAcceleration;
    std::cout << "Введите высоту набора h (м): ";
    std::cin >> height;
    std::cout << "Введите вертикальное ускорение ay (м/с^2): ";
    std::cin >> verticalAcceleration;

    if (!std::cin || height <= 0 || verticalAcceleration <= 0) {
        std::cerr << "Ошибка: высота и ускорение должны быть больше нуля.\n";
        return 1;
    }

    const double time = std::sqrt(2.0 * height / verticalAcceleration);
    std::cout << std::fixed << std::setprecision(3)
              << "Время набора высоты t = " << time << " с\n";
}
