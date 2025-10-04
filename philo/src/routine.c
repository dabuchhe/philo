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

void	eating(t_philo *philo)
{
	if (philo->data->nb_philo == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		lock_and_print(philo->id, "has taken a fork", philo->data);
		ft_usleep(philo->data->t_die * 1000);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		lock_and_print(philo->id, "has taken a fork", philo->data);
		pthread_mutex_lock(philo->l_fork);
		lock_and_print(philo->id, "has taken a fork", philo->data);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		// bool
		lock_and_print(philo->id, "has taken a fork", philo->data);
		pthread_mutex_lock(philo->r_fork);
		lock_and_print(philo->id, "has taken a fork", philo->data);
	}
	lock_and_print(philo->id, "is eating", philo->data);
	pthread_mutex_lock(&philo->mtx->eat);
	philo->t_last_eat = get_time_ms();
	if (philo->nb_meal >= philo->data->must_eat && philo->data->must_eat != -1)
		philo->finish = true;
	ft_usleep(philo->data->t_eat * 1000);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->mtx->eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->mtx->start);
	pthread_mutex_unlock(&philo->mtx->start);
	if (philo->id % 2 == 0)
	{
		lock_and_print(philo->id, "is thinking", philo->data);
		ft_usleep(philo->data->t_eat / 2);
	}
	while (1)
	{
		// if (eating)
			// return ();
		if (check_philo_died(philo))
			return (NULL);
		eating(philo);
		if (check_philo_died(philo))
			return (NULL);
		lock_and_print(philo->id, "is sleeping", philo->data);
		if (ft_usleep_sleep(philo->data->t_sleep * 1000, philo))
			return (NULL);
		lock_and_print(philo->id, "is thinking", philo->data);
		if (philo->data->t_die - philo->data->t_eat > philo->data->t_eat + philo->data->t_sleep)
			usleep(philo->data->t_eat * 1000);
		usleep(50);
	}
	return (NULL);
}

// void	*monitoring(void *arg)
// {
// 	t_data *data;
// 	int i;

// 	data = arg;
// 	while (1)
// 	{
// 		i = 0;
// 		while (i < data->nb_philo)
// 		{
// 			if (check_death(&data->philo[i]))
// 				return (NULL);
// 			i++;
// 		}
// 		usleep(200);
// 	}
// }

int	launch_routine(t_data *data)
{
	int i;

	i = 0;
	pthread_mutex_lock(&data->mtx.start);
	data->t_start = get_time_ms();
	while (i < data->nb_philo)
	{
		data->philo[i].t_last_eat = data->t_start;
		if (w_pthread_create(&data->philo[i].thread, routine, &data->philo[i],
			data))
			return (1);
		i++;
	}
	pthread_mutex_unlock(&data->mtx.start);
	return (0);
}
