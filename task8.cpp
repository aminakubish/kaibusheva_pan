#include <algorithm>
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
    double thrust;
    double liftCoefficient;
    double dragCoefficient;
    double climbTime = std::numeric_limits<double>::infinity();
};

int main() {
    setupRussianConsole();
    constexpr double g = 9.81;
    int count;
    double density, velocity, wingArea, height;
    std::cout << "Введите количество самолетов: ";
    std::cin >> count;
    std::cout << "Введите общие значения rho, скорости, площади крыла и высоты: ";
    std::cin >> density >> velocity >> wingArea >> height;

    if (!std::cin || count <= 0 || density <= 0 || velocity < 0 || wingArea <= 0 || height <= 0) {
        std::cerr << "Ошибка: введены некорректные данные.\n";
        return 1;
    }

    std::vector<Aircraft> aircraft(count);
    for (int i = 0; i < count; ++i) {
        aircraft[i].name = "Самолет " + std::to_string(i + 1);
        std::cout << aircraft[i].name << " - введите массу, тягу, CL и CD: ";
        std::cin >> aircraft[i].mass >> aircraft[i].thrust
                 >> aircraft[i].liftCoefficient >> aircraft[i].dragCoefficient;
        if (!std::cin || aircraft[i].mass <= 0 || aircraft[i].thrust < 0 ||
            aircraft[i].liftCoefficient < 0 || aircraft[i].dragCoefficient < 0) {
            std::cerr << "Ошибка: некорректные параметры самолета.\n";
            return 1;
        }

        const double lift = 0.5 * density * velocity * velocity * wingArea
                            * aircraft[i].liftCoefficient;
        const double ay = (lift - aircraft[i].mass * g) / aircraft[i].mass;
        if (ay > 0)
            aircraft[i].climbTime = std::sqrt(2.0 * height / ay);
    }

    std::sort(aircraft.begin(), aircraft.end(), [](const Aircraft& a, const Aircraft& b) {
        return a.climbTime < b.climbTime;
    });

    std::cout << std::fixed << std::setprecision(3)
              << "\nСамолеты по возрастанию времени набора высоты:\n";
    for (const auto& plane : aircraft) {
        std::cout << plane.name << ": ";
        if (std::isfinite(plane.climbTime))
            std::cout << plane.climbTime << " с\n";
        else
            std::cout << "не может набирать высоту при заданных параметрах\n";
    }
}
