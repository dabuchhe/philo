/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 23:46:22 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/12 23:46:22 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&(data->mtx.fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->mtx.death));
	pthread_mutex_destroy(&(data->mtx.print));
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!arg_is_valid(ac, av))
		return (1);
	init_all(av, &data);
	launch_routine(&data);
	join_threads(&data);
	print_all(&data);
	destroy_mutex(&data);
	// free_all(&data);
	return (NO_ERROR);
}

/*
	init_data();
	init_mutex();
	init_philo();
*/