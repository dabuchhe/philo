/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
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
	pthread_mutex_destroy(&(data->mtx.start));
	pthread_mutex_destroy(&(data->mtx.death));
	pthread_mutex_destroy(&(data->mtx.print));
	pthread_mutex_destroy(&(data->mtx.eat));
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

int	clean_exit(int err, t_data *data)
{
	join_threads(data);
	destroy_mutex(data);
	if (data->mtx.fork)
	{
		free(data->mtx.fork);
		data->mtx.fork = NULL;
	}
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	return (err);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!arg_is_valid(ac, av))
		return (1);
	if (init_all(av, &data))
		return (1);
	if (launch_routine(&data))
		return (1);
	return (clean_exit(0, &data));
}
