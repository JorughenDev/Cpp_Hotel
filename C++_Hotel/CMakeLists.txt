cmake_minimum_required(VERSION 3.26)
project(ElMochileroReserva)

set(CMAKE_CXX_STANDARD 17)

add_executable(ElMochileroReserva main.cpp
        habitacion.h
        cama.h
        huesped.h
        hostel.cpp
        habitacion.cpp
        hostel.h
        cama.cpp
        huesped.cpp)
