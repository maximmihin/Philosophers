#include "../include/philosophers.h"

void	philo_print(t_data *all_data, int id, char *msg)
{
	pthread_mutex_lock(&all_data->print_fork);
	printf("%lu %d %s\n", get_time() - all_data->start_time, id + 1, msg);
	pthread_mutex_unlock(&all_data->print_fork);
}

void	philo_sleep(t_philo *philo, t_data *all_data)
{
	unsigned long	start_sleep;

	start_sleep = get_time();
	philo_print(all_data, philo->id, "is sleeping");
	while (get_time() < start_sleep + all_data->input_param.time_to_sleep)
		usleep(330);

}

void	philo_eat(t_philo *philo, t_data *all_data)
{
	pthread_mutex_lock(&philo->l_fork);
	if (philo->state == DIED)
		return ;
	philo_print(all_data, philo->id, "has taken a fork");

	pthread_mutex_lock(&philo->r_fork);
	if (philo->state == DIED)
		return ;
	philo_print(all_data, philo->id, "has taken a fork");

	philo->last_eat = get_time();
	if (philo->state == DIED)
		return ;
	philo_print(all_data, philo->id, "is eating");
	philo->time_eat++;
	philo->state = EATING;
	while (get_time() < philo->last_eat + all_data->input_param.time_to_eat)
		usleep(330);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);

	if (philo->time_eat == all_data->input_param.philo_must_eat)
		kill_all(all_data);
}

void	philo_think(t_philo *philo, t_data *all_data)
{
	if (philo->state == DIED)
		return ;
	philo_print(all_data, philo->id, "is thinking");
	/// ???
}

void	*thread_philo(void *param)
{
	t_data	*all_data;
	t_philo	*philo;

	philo = (t_philo *)param;
	philo->last_eat = get_time();
	philo->state = STARTED;

	all_data = philo->all_data;
	if (all_data->input_param.count % 2 && all_data->input_param.count != 1
		&& philo->id + 1 == all_data->input_param.count)
		philo_think(philo, all_data);
	else if (!(philo->id % 2))
	{
		philo_sleep(philo, all_data);
		philo_think(philo, all_data);
	}
	else
	{
		philo_eat(philo, all_data);
		philo_sleep(philo, all_data);
		philo_think(philo, all_data);
	}
	while(philo->state != DIED)
	{
		philo_eat(philo, all_data);

		philo_sleep(philo, all_data);

		philo_think(philo, all_data);
	}
	/// free fork
	return (NULL);
}

int	start_philo(t_data	*all_data)
{
	int i = 0;

	while (i < all_data->input_param.count)
	{
		if (pthread_create(&all_data->pthread_list[i], NULL,
						   thread_philo, &all_data->pthread_list[i]) != 0)
			return (0);
		pthread_detach(all_data->pthread_list[i]);
		i++;
	}
	return (1);
}

