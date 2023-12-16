cmake_minimum_required(VERSION 3.27)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1
        src/MainFile.cpp
        "src/Circle Volume Calculator.cpp"
        src/CVC.h
        "src/Averages Calc.cpp"
        src/AC.h
        "src/Character Classes.cpp"
        src/CC.h
        src/Include.h
        "src/File Management.cpp"
        src/FM.h)
