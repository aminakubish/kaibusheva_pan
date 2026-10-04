#include <iomanip>
#include <iostream>
#include "console_utf8.h"

int main() {
    setupRussianConsole();
    double area, velocity, density, liftCoefficient;
    std::cout << "Введите площадь крыла S (м^2): ";
    std::cin >> area;
    std::cout << "Введите скорость полета V (м/с): ";
    std::cin >> velocity;
    std::cout << "Введите плотность воздуха rho (кг/м^3): ";
    std::cin >> density;
    std::cout << "Введите коэффициент подъемной силы CL: ";
    std::cin >> liftCoefficient;

    if (!std::cin || area <= 0 || velocity < 0 || density <= 0 || liftCoefficient < 0) {
        std::cerr << "Ошибка: введены некорректные данные.\n";
        return 1;
    }

    const double lift = 0.5 * density * velocity * velocity * area * liftCoefficient;
    std::cout << std::fixed << std::setprecision(2)
              << "Подъемная сила L = " << lift << " Н\n";
}
