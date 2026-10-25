cmake_minimum_required(VERSION 3.16)
project(seminar3_tasks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

foreach(task RANGE 1 10)
    if(task LESS 10)
        set(task_file "seminar3_task0${task}.cpp")
    else()
        set(task_file "seminar3_task${task}.cpp")
    endif()
    add_executable(seminar3_task${task} ${task_file})
endforeach()

foreach(task RANGE 1 5)
    add_executable(seminar3_extra${task} seminar3_extra0${task}.cpp)
endforeach()
