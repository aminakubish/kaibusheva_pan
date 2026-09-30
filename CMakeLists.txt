cmake_minimum_required(VERSION 3.16)
project(first_10_aircraft_tasks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

foreach(task RANGE 1 10)
    add_executable(task${task} task${task}.cpp)
endforeach()
