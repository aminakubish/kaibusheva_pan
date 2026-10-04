#include <iomanip>
#include <iostream>
#include "console_utf8.h"

double calculateDrag(double density, double velocity, double area, double dragCoefficient) {
    return 0.5 * density * velocity * velocity * area * dragCoefficient;
}

int main() {
    setupRussianConsole();
    double area, velocity, density, dragCoefficient;
    std::cout << "Введите площадь крыла S (м^2): ";
    std::cin >> area;
    std::cout << "Введите скорость полета V (м/с): ";
    std::cin >> velocity;
    std::cout << "Введите плотность воздуха rho (кг/м^3): ";
    std::cin >> density;
    std::cout << "Введите коэффициент сопротивления CD: ";
    std::cin >> dragCoefficient;

    if (!std::cin || area <= 0 || velocity < 0 || density <= 0 || dragCoefficient < 0) {
        std::cerr << "Ошибка: введены некорректные данные.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2)
              << "Сила аэродинамического сопротивления D = "
              << calculateDrag(density, velocity, area, dragCoefficient) << " Н\n";
}
