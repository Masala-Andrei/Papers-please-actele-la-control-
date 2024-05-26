cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled main.cpp
        src/Game.cpp
        headers/Game.h
        src/Document.cpp
        headers/Document.h
        src/Passport.cpp
        headers/Passport.h
        src/Statistics.cpp
        headers/Statistics.h
        src/Immigrant.cpp
        headers/Immigrant.h
        src/Entry_Permit.cpp
        headers/Entry_Permit.h
        src/Identity_Card.cpp
        headers/Identity_Card.h)
