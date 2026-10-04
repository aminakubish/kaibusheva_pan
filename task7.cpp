#include <iomanip>
#include <iostream>
#include "console_utf8.h"

int main() {
    setupRussianConsole();
    constexpr double g = 9.81;
    double mass, thrust, lift, drag;
    std::cout << "Введите массу m (кг), тягу T (Н), подъемную силу L (Н)"
                 " и сопротивление D (Н): ";
    std::cin >> mass >> thrust >> lift >> drag;

    if (!std::cin || mass <= 0 || thrust < 0 || lift < 0 || drag < 0) {
        std::cerr << "Ошибка: введены некорректные данные.\n";
        return 1;
    }

    const double longitudinalAcceleration = (thrust - drag) / mass;
    const double verticalAcceleration = (lift - mass * g) / mass;

    const char* mode;
    if (verticalAcceleration > 0.5)
        mode = "набор высоты";
    else if (verticalAcceleration >= 0.0)
        mode = "горизонтальный полет";
    else
        mode = "снижение";

    std::cout << std::fixed << std::setprecision(3)
              << "Ускорение по направлению движения = " << longitudinalAcceleration << " м/с^2\n"
              << "Вертикальное ускорение = " << verticalAcceleration << " м/с^2\n"
              << "Определенный режим полета: " << mode << '\n';
}
