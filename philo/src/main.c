/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 02:40:28 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/26 02:40:30 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	if (pthread_create(&all_data->monitor_thread, 0, monitor, all_data) != 0)
		return (error("Error : Failed start monitor_thread\n"));
	if (!(start_philo(all_data)))
		return (error("Error : Failed to start threads\n"));
	if (pthread_join(all_data->monitor_thread, NULL))
		return (error("Error : Failed join monitor thread\n"));
	if (!join_philo_thread(all_data))
		return (error("Error : Failed join philo threads\n"));
	if (!destroy_mutexes(all_data))
		return (error("Error : Failed destroy mutexes\n"));
	free_all_data(&all_data);
	return (0);
}
