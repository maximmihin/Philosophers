cmake_minimum_required(VERSION 3.21)
project(philo C)

set(CMAKE_C_STANDARD 11)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread")

include_directories(philo/include)

add_executable(philo
        philo/src/main.c
		philo/src/init_input.c
		philo/src/libft_func/ft_atoi.c
		philo/src/libft_func/ft_itoa.c
		philo/src/libft_func/ft_strlen.c
		philo/src/libft_func/ft_strncmp.c
		philo/src/start_philo.c
		philo/src/init_philo_struct.c
		philo/src/start_monitor.c
		philo/src/utils.c)
