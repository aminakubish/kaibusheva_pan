#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "console_utf8.h"

struct Aircraft {
    double mass;
    double wingArea;
    double thrust;
    double liftCoefficient;
    double dragCoefficient;
};

int main() {
    setupRussianConsole();
    int count;
    double density, velocity;
    std::cout << "Введите количество самолетов N: ";
    std::cin >> count;
    std::cout << "Введите плотность воздуха rho (кг/м^3) и скорость V (м/с): ";
    std::cin >> density >> velocity;

    if (!std::cin || count <= 0 || density <= 0 || velocity < 0) {
        std::cerr << "Ошибка: введены некорректные данные.\n";
        return 1;
    }

    std::vector<Aircraft> aircraft(count);
    double bestAcceleration = -std::numeric_limits<double>::infinity();
    int leader = -1;

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < count; ++i) {
        std::cout << "Самолет " << i + 1
                  << " - введите массу, площадь крыла, тягу, CL и CD: ";
        std::cin >> aircraft[i].mass >> aircraft[i].wingArea >> aircraft[i].thrust
                 >> aircraft[i].liftCoefficient >> aircraft[i].dragCoefficient;

        const auto& plane = aircraft[i];
        if (!std::cin || plane.mass <= 0 || plane.wingArea <= 0 || plane.thrust < 0 ||
            plane.liftCoefficient < 0 || plane.dragCoefficient < 0) {
            std::cerr << "Ошибка: некорректные параметры самолета.\n";
            return 1;
        }

        const double dynamicPressure = 0.5 * density * velocity * velocity;
        const double lift = dynamicPressure * plane.wingArea * plane.liftCoefficient;
        const double drag = dynamicPressure * plane.wingArea * plane.dragCoefficient;
        const double acceleration = (plane.thrust - drag) / plane.mass;

        std::cout << "  Подъемная сила L = " << lift << " Н, сопротивление D = "
                  << drag << " Н, ускорение = " << acceleration << " м/с^2\n";
        if (acceleration > bestAcceleration) {
            bestAcceleration = acceleration;
            leader = i;
        }
    }

    std::cout << "Наибольшее ускорение имеет самолет " << leader + 1
              << " (" << bestAcceleration << " м/с^2)\n";
}
