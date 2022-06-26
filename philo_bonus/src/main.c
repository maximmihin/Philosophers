/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 02:46:51 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/26 02:46:53 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data		*all_data;
	pthread_t	thread_limit_monitor;
	int			i;

	if (argc != 5 && argc != 6)
		return (error("Error : Invalid input\n"));

	all_data = init_all_data(argc, argv);
	if (!all_data)
		return (error("Error : Failed init all_data\n"));

	if (all_data->input_param.philo_must_eat != -1)
	{
		if (pthread_create(&thread_limit_monitor, 0, monitor_limit,	all_data))
			return (0);
		pthread_detach(thread_limit_monitor);
	}

	i = 0;
	while (i < all_data->input_param.count)
	{
		all_data->philo_pids[i] = fork();
		if (all_data->philo_pids[i] == 0)
		{
			if (!start_philo(i, all_data))
				error("Error : failed start philo\n");
			break ;
		}
		i++;
	}
	waitpid(-1, NULL, 0);
	kill(-1, SIGQUIT);
	destroy_semaphores(all_data);
	exit(0);
}
