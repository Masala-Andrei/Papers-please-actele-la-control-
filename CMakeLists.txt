cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled main.cpp
        Game.cpp
        Game.h
        Document.cpp
        Document.h
        Passport.cpp
        Passport.h
        Statistics.cpp
        Statistics.h
        Immigrant.cpp
        Immigrant.h
        Entry_Permit.cpp
        Entry_Permit.h
        Identity_Card.cpp
        Identity_Card.h)
