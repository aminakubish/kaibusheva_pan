#include <iomanip>
#include <iostream>
#include <vector>
#include "console_utf8.h"

int main() {
    setupRussianConsole();
    int count;
    double wingArea, liftCoefficient;
    std::cout << "Введите количество точек траектории: ";
    std::cin >> count;
    std::cout << "Введите площадь крыла S (м^2) и коэффициент CL: ";
    std::cin >> wingArea >> liftCoefficient;

    if (!std::cin || count <= 0 || wingArea <= 0 || liftCoefficient < 0) {
        std::cerr << "Ошибка: введены некорректные данные.\n";
        return 1;
    }

    std::vector<double> velocities(count), densities(count);
    for (int i = 0; i < count; ++i) {
        std::cout << "Точка " << i + 1
                  << " - введите скорость (м/с) и плотность воздуха (кг/м^3): ";
        std::cin >> velocities[i] >> densities[i];
        if (!std::cin || velocities[i] < 0 || densities[i] <= 0) {
            std::cerr << "Ошибка: некорректные данные траектории.\n";
            return 1;
        }
    }

    std::cout << std::fixed << std::setprecision(2)
              << "\nШаг\tСкорость\tПлотность\tПодъемная сила\n";
    for (int i = 0; i < count; ++i) {
        const double lift = 0.5 * densities[i] * velocities[i] * velocities[i]
                            * wingArea * liftCoefficient;
        std::cout << i + 1 << '\t' << velocities[i] << "\t\t" << densities[i]
                  << "\t\t" << lift << " Н\n";
    }
}
