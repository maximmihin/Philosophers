#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

/// to del
#include <stdio.h>


typedef struct s_input
{
	int	count;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int	philo_must_eat;
} t_input;

t_input	init_input(int argc, char **argv);

#endif //PHILOSOPHERS_H
