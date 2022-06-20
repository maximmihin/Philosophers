#include "../include/philosophers.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				minus;

	minus = 1;
	num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		   || *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((((num * 10) + (*str - '0')) < num) && (minus == 1))
			return (-1);
		else if ((((num * 10) + (*str - '0')) < num) && (minus == -1))
			return (0);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return ((int)(num * minus));
}

t_input	init_input(int argc, char **argv)
{
	t_input	input;

	input.count = ft_atoi(argv[1]);
	input.time_to_die = ft_atoi(argv[2]);
	input.time_to_eat = ft_atoi(argv[3]);
	input.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input.philo_must_eat = ft_atoi(argv[5]);
	else
		input.philo_must_eat = -1;

	/// TODO add check non-numeric symbols

	if (input.count <= 0 || input.time_to_die <= 0 || input.time_to_eat  <= 0
		|| input.time_to_sleep <= 0 || (argc == 6 && input.philo_must_eat <= 0))
		input.count = 0;
	return (input);
}

