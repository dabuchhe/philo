/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/09/12 19:28:18 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/12 19:28:18 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// void	*routine(void *args)
// {
// 	t_philo *philo;

// 	philo = (t_philo *)args;
// 	pthread_mutex_lock(philo->l_fork);
// 	mutex_and_print();
// 	pthread_mutex_lock(philo->r_fork);
// 	mutex_and_print();
// 	check_eat_nb ()?;
// 	update_time();
// 	update_eat_nb();
// 	sleep();

// 	pthread_mutex_unlock(philo->l_fork);
// 	pthread_mutex_unlock(philo->r_fork);
// 	pthread_mutex_unlock(&philo->mtx->print);
// 	return (NULL);
// }

void	thinking(t_philo *philo)
{
	lock_and_print(philo->id, "is thinking", philo->data);
	usleep(50);
}

void	sleeping(t_philo *philo)
{
	lock_and_print(philo->id, "is sleeping", philo->data);
	ft_usleep(philo->data->t_sleep * 1000, philo);
}

void	eating(t_philo *philo)
{
	w_pthread_mutex_lock(philo->l_fork, philo->data);
	lock_and_print(philo->id, "has taken a fork", philo->data);
	w_pthread_mutex_lock(philo->r_fork, philo->data);
	lock_and_print(philo->id, "has taken a fork", philo->data);
	lock_and_print(philo->id, "is eating", philo->data);
	philo->nb_meal++;
	philo->t_last_eat = get_time_ms();
	if (philo->nb_meal >= philo->data->must_eat && philo->data->must_eat != -1)
	{
		pthread_mutex_lock(&philo->mtx->death);
		philo->finish = true;
		pthread_mutex_unlock(&philo->mtx->death);
	}
	ft_usleep(philo->data->t_eat * 1000, philo);
	w_pthread_mutex_unlock(philo->l_fork, philo->data);
	w_pthread_mutex_unlock(philo->r_fork, philo->data);
}

void	*routine(void *args)
{
	t_philo *philo = (t_philo *)args;

	if (philo->id % 2 == 0)
	{
		thinking(philo);
		usleep(50);
	}
	while (1)
	{
		if (check_death(philo))
			return (NULL);
		eating(philo);
		usleep(50);
		if (check_death(philo))
			return (NULL);
		sleeping(philo);
		usleep(50);
		if (check_death(philo))
			return (NULL);
		thinking(philo);
		usleep(50);
	}
	return (NULL);
}

void	*monitoring(void *arg)
{
	t_data *data = arg;
	int i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (check_death(&data->philo[i]))
				return (NULL);
			i++;
		}
		usleep(200);
	}
}

int	launch_routine(t_data *data)
{
	pthread_t monitor;
	int i;

	i = 0;
	data->t_start = get_time_ms();
	while (i < data->nb_philo)
	{
		data->philo[i].t_last_eat = data->t_start;
		w_pthread_create(&data->philo[i].thread, &data->philo[i], data);
		i++;
	}
	pthread_create(&monitor, NULL, monitoring, data);
	pthread_join(monitor, NULL);
	return (0);
}
