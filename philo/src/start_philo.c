#include "../include/philosophers.h"

int		is_some_dead(t_philo *philo);
void	philo_eat(t_philo *philo, t_data *all_data);
void	philo_sleep(t_philo *philo, t_data *all_data);

void	philo_think(t_philo *philo, t_data *all_data)
{
	if (is_some_dead(philo))
		return ;
	philo_print(all_data, philo->id, "is thinking");
}

void	first_move(t_data *all_data, t_philo *philo)
{
	if (philo->id % 2)
	{
		philo_sleep(philo, all_data);
		philo_think(philo, all_data);
	}
	else if (philo->id + 1 == all_data->input_param.count)
		philo_think(philo, all_data);
}

void	*thread_philo(void *param)
{
	t_data	*all_data;
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(philo->check_hunger);
	philo->last_eat = get_time();
	philo->state = STARTED;
	pthread_mutex_unlock(philo->check_hunger);
	all_data = philo->all_data;
	first_move(all_data, philo);
	while (1)
	{
		philo_eat(philo, all_data);
		if (is_some_dead(philo))
			break ;
		philo_sleep(philo, all_data);
		if (is_some_dead(philo))
			break ;
		philo_think(philo, all_data);
		if (is_some_dead(philo))
			break ;
	}
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (NULL);
}

int	start_philo(t_data	*all_data)
{
	int	i;

	i = 0;
	while (i < all_data->input_param.count)
	{
		if (pthread_create(&all_data->pthread_list[i], NULL,
				thread_philo, &all_data->philo_list[i]) != 0)
			return (0);
		pthread_detach(all_data->pthread_list[i]);
		i++;
	}
	return (1);
}
