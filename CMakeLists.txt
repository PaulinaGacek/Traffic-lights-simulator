cmake_minimum_required(VERSION 3.17)
project(StateMachine)

set(CMAKE_CXX_STANDARD 17)

add_executable(StateMachine src/main.cpp src/LightState.h src/TrafficLights.cpp src/TrafficLights.h)