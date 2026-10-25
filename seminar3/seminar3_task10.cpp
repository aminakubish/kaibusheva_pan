#include <iomanip>
#include <iostream>
#include <vector>
#include "seminar3_console_utf8.h"

struct Point {
    double x;
    double y;
    double z;
};

class Rocket {
public:
    Rocket(double mass, double vx, double vy, double vz)
        : mass_(mass), velocity_{vx, vy, vz}, position_{0.0, 0.0, 0.0}, landed_(false) {}

    void updatePosition(double dt) {
        position_.x += velocity_.x * dt;
        position_.y += velocity_.y * dt;
        position_.z += velocity_.z * dt;
        if (position_.z <= 0.0 && velocity_.z < 0.0) {
            position_.z = 0.0;
            landed_ = true;
        }
    }

    void changeVelocity(double dvx, double dvy, double dvz) {
        velocity_.x += dvx;
        velocity_.y += dvy;
        velocity_.z += dvz;
    }

    Point getPosition() const { return position_; }
    double getMass() const { return mass_; }
    bool hasLanded() const { return landed_; }

private:
    double mass_;
    Point velocity_;
    Point position_;
    bool landed_;
};

int main() {
    setupRussianConsole();

    constexpr double dt = 0.1;
    constexpr double simulationTime = 10.0;
    constexpr double g = 9.8;
    constexpr int stepCount = static_cast<int>(simulationTime / dt);

    std::vector<Rocket> squad;
    squad.reserve(5);
    squad.emplace_back(1000.0, 10.0, 0.0, 50.0);
    squad.emplace_back(900.0, 15.0, -5.0, 40.0);
    squad.emplace_back(1100.0, 8.0, 4.0, 55.0);
    squad.emplace_back(950.0, -6.0, 12.0, 45.0);
    squad.emplace_back(1050.0, 5.0, 7.0, 60.0);

    std::vector<std::vector<Point>> trajectories(squad.size());
    for (std::size_t i = 0; i < squad.size(); ++i) {
        trajectories[i].push_back(squad[i].getPosition());
        for (int step = 0; step < stepCount && !squad[i].hasLanded(); ++step) {
            // Полушаг скорости до и после координаты дает точное движение
            // при постоянном ускорении свободного падения.
            squad[i].changeVelocity(0.0, 0.0, -0.5 * g * dt);
            squad[i].updatePosition(dt);
            if (!squad[i].hasLanded())
                squad[i].changeVelocity(0.0, 0.0, -0.5 * g * dt);
            trajectories[i].push_back(squad[i].getPosition());
        }
    }

    std::cout << "Конечные положения ракет после 10 секунд полета:\n";
    std::cout << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < squad.size(); ++i) {
        const Point p = squad[i].getPosition();
        std::cout << "Ракета " << i + 1 << " (масса " << squad[i].getMass()
                  << " кг): x = " << p.x << " м, y = " << p.y
                  << " м, z = " << p.z << " м; точек траектории: "
                  << trajectories[i].size() << "; состояние: "
                  << (squad[i].hasLanded() ? "приземлилась" : "в полете") << ".\n";
    }
}
