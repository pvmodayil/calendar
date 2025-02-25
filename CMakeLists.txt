cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CalendarApp)

# Specify the executable target
add_executable(calendar main.cpp calendar.cpp event.cpp)

# Include directories if needed
include_directories(.)