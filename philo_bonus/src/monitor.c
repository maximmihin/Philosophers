/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 02:47:17 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/26 02:47:19 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*monitor_hunger(void *philo_param)
{
	t_philo			*philo;
	unsigned long	time_to_die;

	usleep(1000);
	philo = (t_philo *)philo_param;
	time_to_die = philo->time_to_die;
	while (1)
	{
		sem_wait(philo->sem_eat_update);
		if (get_time() - philo->last_eat > time_to_die)
			break ;
		sem_post(philo->sem_eat_update);
		usleep(330);
	}
	philo_print(philo, "died");
	sem_close(philo->sem_eat_update);
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
		i++;
	}
	printf("STOP\n");
	kill(-1, SIGQUIT);
	return (NULL);
}
