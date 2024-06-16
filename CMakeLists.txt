cmake_minimum_required(VERSION 3.28)
project(CourseProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(CourseProject main.cpp
        TaskInterface.h
        Task.cpp
        Task.h
        Type.cpp
        Type.h
        Time.cpp
        Time.h
        Controller.h
        Date.cpp
        Date.h
)
