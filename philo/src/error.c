#include "../include/philosophers.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}
