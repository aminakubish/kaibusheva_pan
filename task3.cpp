#include <iomanip>
#include <iostream>
#include "console_utf8.h"

int main() {
    setupRussianConsole();
    constexpr double g = 9.81;
    double mass, lift, drag, thrust;
    std::cout << "Введите массу самолета m (кг): ";
    std::cin >> mass;
    std::cout << "Введите подъемную силу L (Н): ";
    std::cin >> lift;
    std::cout << "Введите силу сопротивления D (Н): ";
    std::cin >> drag;
    std::cout << "Введите тягу двигателя T (Н): ";
    std::cin >> thrust;

    if (!std::cin || mass <= 0 || lift < 0 || drag < 0 || thrust < 0) {
        std::cerr << "Ошибка: введены некорректные данные.\n";
        return 1;
    }

    const double longitudinalAcceleration = (thrust - drag) / mass;
    const double verticalAcceleration = (lift - mass * g) / mass;

    std::cout << std::fixed << std::setprecision(3)
              << "Ускорение по направлению движения ax = " << longitudinalAcceleration << " м/с^2\n"
              << "Вертикальное ускорение ay = " << verticalAcceleration << " м/с^2\n";
}
