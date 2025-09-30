/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/09/06 20:05:50 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/06 20:05:50 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>

static int	init_mutex(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->mtx.print, NULL);
	pthread_mutex_init(&data->mtx.death, NULL);
	data->mtx.fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->mtx.fork)
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->mtx.fork[i], NULL);
		i++;
	}
	return (0);
}

static int	init_philo(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo[i].nb_meal = 0;
		data->philo[i].finish = false;
		data->philo[i].data = data;
		data->philo[i].mtx = &data->mtx;
		data->philo[i].l_fork = &data->mtx.fork[i];
		data->philo[i].r_fork = &data->mtx.fork[(i + 1) % data->nb_philo];
		i++;
	}
	return (0);
}

static int	init_data(char **av, t_data *data)
{
	data->nb_philo = atoi_secure(av[1]);
	data->t_die = atoi_secure(av[2]);
	data->t_eat = atoi_secure(av[3]);
	data->t_sleep = atoi_secure(av[4]);
	if (av[5])
		data->must_eat = atoi_secure(av[5]);
	else
		data->must_eat = -1;
	data->philo_died = false;
	return (0);
}

int	init_all(char **av, t_data *data)
{
	init_data(av, data);
	init_mutex(data);
	init_philo(data);
	return (0);
}
