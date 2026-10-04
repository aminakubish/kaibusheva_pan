#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "console_utf8.h"

struct Aircraft {
    std::string name;
    double mass;
    double wingArea;
    double thrust;
    double liftCoefficient;
    double dragCoefficient;
};

int main() {
    setupRussianConsole();
    constexpr double g = 9.81;
    double density, velocity, height;
    std::cout << "Введите плотность воздуха rho (кг/м^3), скорость V (м/с) и высоту h (м): ";
    std::cin >> density >> velocity >> height;

    std::vector<Aircraft> aircraft(3);
    for (int i = 0; i < 3; ++i) {
        aircraft[i].name = "Самолет " + std::to_string(i + 1);
        std::cout << aircraft[i].name
                  << " - введите массу, площадь крыла, тягу, CL и CD: ";
        std::cin >> aircraft[i].mass >> aircraft[i].wingArea >> aircraft[i].thrust
                 >> aircraft[i].liftCoefficient >> aircraft[i].dragCoefficient;
    }

    if (!std::cin || density <= 0 || velocity < 0 || height <= 0) {
        std::cerr << "Ошибка: введены некорректные данные.\n";
        return 1;
    }

    double bestTime = std::numeric_limits<double>::infinity();
    std::string bestName = "none";
    std::cout << std::fixed << std::setprecision(2);

    for (const auto& plane : aircraft) {
        if (plane.mass <= 0 || plane.wingArea <= 0 || plane.thrust < 0 ||
            plane.liftCoefficient < 0 || plane.dragCoefficient < 0) {
            std::cerr << "Ошибка: параметры самолета должны быть корректными.\n";
            return 1;
        }

        const double dynamicPressure = 0.5 * density * velocity * velocity;
        const double lift = dynamicPressure * plane.wingArea * plane.liftCoefficient;
        const double drag = dynamicPressure * plane.wingArea * plane.dragCoefficient;
        const double ax = (plane.thrust - drag) / plane.mass;
        const double ay = (lift - plane.mass * g) / plane.mass;

        std::cout << plane.name << ": подъемная сила L = " << lift
                  << " Н, сопротивление D = " << drag << " Н, ax = " << ax
                  << " м/с^2, ay = " << ay << " м/с^2";
        if (ay > 0) {
            const double time = std::sqrt(2.0 * height / ay);
            std::cout << ", время набора высоты = " << time << " с";
            if (time < bestTime) {
                bestTime = time;
                bestName = plane.name;
            }
        } else {
            std::cout << ", самолет не может набирать высоту при этих параметрах";
        }
        std::cout << '\n';
    }

    if (bestName != "none")
        std::cout << "Быстрее всех наберет высоту: " << bestName
                  << " (" << bestTime << " с)\n";
    else
        std::cout << "Ни один самолет не может набрать высоту при заданных параметрах.\n";
}
