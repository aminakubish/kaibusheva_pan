# Задачи третьего семинара

В папке находятся решения 10 основных и 5 дополнительных задач по `std::vector` и алгоритмам STL.

Эту папку нужно добавить в репозиторий целиком под именем `seminar3`, не перемещая файлы в корень.

- `seminar3_task01.cpp`–`seminar3_task10.cpp` — основные задачи.
- `seminar3_extra01.cpp`–`seminar3_extra05.cpp` — дополнительные задачи.

Все программы выводят подсказки и результаты на русском языке.

Пример запуска:

```bash
g++ -std=c++17 seminar3_task01.cpp -o seminar3_task01
./seminar3_task01
```

Сборка всех программ:

```bash
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
```
