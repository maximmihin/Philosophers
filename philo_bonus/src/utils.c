/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 02:49:03 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/26 02:49:06 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <sys/time.h>
#include <stdio.h>

int	ft_strlen(char *str);

int	error(char *str)
{
	write(1, str, ft_strlen(str));
	exit (1);
}

void	philo_print(t_philo *philo, char *msg)
{
	sem_wait(philo->sem_print);
	printf("%lu %d %s\n", get_time() - philo->start_time, philo->id + 1, msg);
	sem_post(philo->sem_print);
}

unsigned long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	destroy_semaphores(t_data *all_data)
{
	int i;

	sem_close(all_data->sem_forks);
	sem_unlink("/philo_forks");
	sem_close(all_data->sem_print);
	sem_unlink("/philo_print");
	if (all_data->input_param.philo_must_eat != -1)
	{
		i = 0;
		while (i < all_data->input_param.count)
		{
			sem_post(all_data->sem_philo_must_eat);
			i++;
		}
		sem_close(all_data->sem_philo_must_eat);
		sem_unlink("/philo_philo_must_eat");
	}
	i = 0;
	while (i < all_data->input_param.count)
	{
		sem_unlink(all_data->child_sem_name[i]);
		i++;
	}
}
