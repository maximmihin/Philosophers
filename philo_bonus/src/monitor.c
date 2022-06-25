#include "../include/philo_bonus.h"

void	*monitor_hunger(void *philo_param)
{
	t_philo	*philo;
	unsigned long	time_to_die;

	usleep(1000);

	philo = (t_philo *)philo_param;
	///

	///
	time_to_die = philo->time_to_die;
	while (1)
	{
		sem_wait(philo->sem_eat_update);
//		printf("id : %d 1 MMM\n", philo->id);
		if (get_time() - philo->last_eat > time_to_die)
		{
//			printf("id : %d 2 MMM\n", philo->id);
			break ;
		}
//		printf("id : %d 3 MMM\n", philo->id);
		sem_post(philo->sem_eat_update);
		usleep(330);
	}
//	printf("id : %d 4 MMM\n", philo->id);
	sem_close(philo->sem_eat_update);
//	printf("id : %d 5 MMM\n", philo->id);
	exit(1);
}

void	*monitor_limit(void *data)
{
	t_data	*all_data;
	int		limit;
	int		i;

	all_data = (t_data *)data;
	limit = all_data->input_param.philo_must_eat;
	i = 0;
	while (i < limit)
	{
		sem_wait(all_data->sem_philo_must_eat);
		printf("RRR\n");
		i++;
	}
	printf("STOP\n");

//	kill(all_data->philo_pids[0], 0);
	kill(-1, 0);
	return (NULL);
}
