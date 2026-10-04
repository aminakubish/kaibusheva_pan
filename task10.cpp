#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include "console_utf8.h"

int main() {
    setupRussianConsole();
    constexpr double g = 9.81;
    double mass, lift, height, minThrust, maxThrust, thrustStep;
    std::cout << "Введите массу m (кг), подъемную силу L (Н) и высоту h (м): ";
    std::cin >> mass >> lift >> height;
    std::cout << "Введите минимальную тягу Tmin, максимальную тягу Tmax"
                 " и шаг изменения тяги deltaT (Н): ";
    std::cin >> minThrust >> maxThrust >> thrustStep;

    if (!std::cin || mass <= 0 || lift < 0 || height <= 0 || minThrust < 0 ||
        maxThrust < minThrust || thrustStep <= 0) {
        std::cerr << "Ошибка: введены некорректные данные.\n";
        return 1;
    }

    double bestTime = std::numeric_limits<double>::infinity();
    double bestThrust = 0.0;

    std::cout << std::fixed << std::setprecision(3)
              << "\nТяга (Н)\tУскорение (м/с^2)\tВремя (с)\n";
    for (double thrust = minThrust; thrust <= maxThrust + thrustStep * 1e-9; thrust += thrustStep) {
        const double verticalAcceleration = (lift + thrust - mass * g) / mass;
        std::cout << thrust << "\t\t" << verticalAcceleration << "\t\t";

        if (verticalAcceleration > 0) {
            const double time = std::sqrt(2.0 * height / verticalAcceleration);
            std::cout << time;
            if (time < bestTime) {
                bestTime = time;
                bestThrust = thrust;
            }
        } else {
            std::cout << "набор высоты невозможен";
        }
        std::cout << '\n';
    }

    if (std::isfinite(bestTime))
        std::cout << "\nОптимальная тяга = " << bestThrust
                  << " Н, минимальное время набора высоты = " << bestTime << " с\n";
    else
        std::cout << "\nНи одно значение тяги не дает положительного ускорения набора высоты.\n";
}
