#include "../include/philosophers.h"

void	kill_all(t_data *all_data)
{
	int	i;

	i = 0;
	while (i < all_data->input_param.count)
	{
		all_data->philo_list[i].state = DIED;
		i++;
	}
}

void	*monitor(void	*param)
{
	t_data	*all_data;
	int on;
	int	i;

	all_data = (t_data *)param;
	on = 1;
	i = 0;
	while (on)
	{
		while (i < all_data->input_param.count)
		{
			if (all_data->philo_list[i].last_eat - get_time()
				> all_data->input_param.time_to_die)
			{
//				all_data->philo_list[i].state = DIED;
				kill_all(all_data);
				on = 0;
				break ;
			}
			i++;
		}
		i = 0;
	}


	return (NULL);
}

int start_monitor(t_data *all_data)
{
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, 0, monitor, all_data) != 0)
		return (0);
	pthread_detach(monitor_thread);



	return (1);
}