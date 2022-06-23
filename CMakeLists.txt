cmake_minimum_required(VERSION 3.18)
project(Philosophers C)

set(CMAKE_C_STANDARD 11)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread -O2")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)



include_directories(philo/include)

add_executable(philo
		philo/src/philo.c
		philo/src/parse_arg.c
		philo/src/libft_func/ft_atoi.c
		philo/src/libft_func/ft_itoa.c
		philo/src/libft_func/ft_strlen.c
		philo/src/libft_func/ft_strncmp.c
		philo/src/start_philo.c
		philo/src/init_philo_struct.c
		philo/src/monitor.c
		philo/src/utils.c
		philo/src/philo_utils.c)

target_link_libraries(philo PRIVATE Threads::Threads)