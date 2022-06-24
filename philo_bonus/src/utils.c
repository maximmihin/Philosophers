#include "../include/philo_bonus.h"
#include <sys/time.h>
#include <stdio.h>

int	ft_strlen(char *str);

int	error(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

unsigned long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
