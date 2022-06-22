#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

/// to del
#include <stdio.h>


typedef struct s_param
{
	int				count;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				philo_must_eat;
}	t_param;

typedef struct s_philo
{
	int 			id;
	int 			state;
	int 			time_eat;
	unsigned long	last_eat;
	pthread_t		*philos_thread;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
	void			*all_data;
}	t_philo;

typedef struct s_data
{
	pthread_t		*pthread_list;
	pthread_mutex_t	*forks_list;
	t_philo			*philo_list;
	t_param			input_param;
	pthread_mutex_t	print_fork;
	unsigned long	start_time;
}	t_data;

enum
{
	NOT_STARTED = 0,
	STARTED = 1,
	TAKE_L_FORK = 2,
	TAKE_F_FORK = 3,
	EATING = 4,
	SLEEPING = 5,
	THINKING = 6,
	DIED = 7
};

t_param	init_input(int argc, char **argv);
int	init_philo_struct(t_data *all_data);
int 	start_monitor(t_data *all_data);
int		start_philo(t_data	*all_data);
unsigned long	get_time(void);
void	kill_all(t_data *all_data);

#endif //PHILOSOPHERS_H
