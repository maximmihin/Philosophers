#include "../include/philosophers.h"

int	init_philo_struct(t_data *all_data)
{
	all_data->pthread_list = (pthread_t *) malloc(sizeof(pthread_t) * all_data->input_param.count);
	all_data->forks_list = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * all_data->input_param.count);
	all_data->philo_list = (t_philo *) malloc(sizeof(t_philo) * all_data->input_param.count);
	if (!all_data->pthread_list || !all_data->forks_list || !all_data->philo_list)
		return (0);

	int i = 0;
	while (i < all_data->input_param.count)
	{
		if (pthread_mutex_init(&all_data->forks_list[i], 0) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&all_data->print_fork, 0) != 0)
		return (0);
	all_data->start_time = get_time();

	i = 0;
	while (i < all_data->input_param.count)
	{
		all_data->philo_list[i].r_fork = all_data->forks_list[i];
		if (i != all_data->input_param.count)
			all_data->philo_list[i].l_fork = all_data->forks_list[i + 1];
		else
			all_data->philo_list[i].l_fork = all_data->forks_list[0];
		all_data->philo_list[i].id = i;
		all_data->philo_list[i].state = NOT_STARTED;
		all_data->philo_list[i].time_eat = 0;
		all_data->philo_list[i].all_data = all_data;
		i++;
	}
	return (1);
}




