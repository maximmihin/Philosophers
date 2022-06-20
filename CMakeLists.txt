cmake_minimum_required(VERSION 3.21)
project(philo C)

set(CMAKE_C_STANDARD 11)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread")

include_directories(philo/include)

add_executable(philo
        philo/src/main.c
        philo/src/error.c philo/src/init_input.c)
