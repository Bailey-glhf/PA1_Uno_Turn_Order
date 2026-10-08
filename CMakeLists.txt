cmake_minimum_required(VERSION 4.3)
project(PA1_Uno_Turn_Order)

set(CMAKE_CXX_STANDARD 20)

add_executable(PA1_Uno_Turn_Order main.cpp
        Player.h
        Stack.h
        List.h
        LinkedList.h
        ArrayList.h
        Node.h)
