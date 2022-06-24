#include "../include/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*all_data;

	if (argc != 5 && argc != 6)
		return (error("Error : Invalid input\n"));
	all_data = (t_data *) malloc(sizeof(t_data));
	if (!all_data)
		return (error("Error : Failed malloc all_data\n"));
	all_data->input_param = init_input(argc, argv);
	if (!all_data->input_param.count)
		return (error("Error : Invalid input\n"));
	if (!(init_all_data(all_data)))
		return (error("Error : Failed to init philo_struct\n"));


	int i = 0;
	while (i < all_data->input_param.count)
	{
		all_data->philo_pids[i] = fork();
		if (all_data->philo_pids[i] == 0)
		{
			start_philo();
		}

		i++;
	}

	free_all_data(&all_data);
	return (0);
}