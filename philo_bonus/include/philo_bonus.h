#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <semaphore.h>

typedef struct s_param
{
	int				count;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				philo_must_eat;
}	t_param;

typedef struct s_data
{
	t_param			input_param;
	pid_t			*philo_pids;
	sem_t			sem_ptint;

}	t_data;


int				error(char *str);
t_param			init_input(int argc, char **argv);
int				init_all_data(t_data *all_data);

#endif //PHILO_BONUS_H
