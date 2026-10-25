#pragma once

#ifdef _WIN32
#include <windows.h>
#endif

inline void setupRussianConsole() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}
