/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:29:02 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/30 01:54:39 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_must_eat(t_data *data)
{
    int i;
    int status;

    status = 0;
    i = 0;
    while (i < data->nb_philo)
    {
        if (data->philo[i].finish == false)
            status = 1;
        i++;
    }
    return (status);
}

int	check_philo_died(t_philo *philo)
{
    int status;
    
    status = 0;
	pthread_mutex_lock(&philo->mtx->death);
	if (philo->data->philo_died)
        status = 1;
    pthread_mutex_unlock(&philo->mtx->death);
    return (status);
}

int	check_time_to_die(t_philo *philo)
{
    int status;

    status = 0;
    pthread_mutex_lock(&philo->mtx->death);
    if (get_time_ms() - philo->t_last_eat > philo->data->t_die)
	{
		philo->data->philo_died = 1;
		lock_and_print(philo->id, "died", philo->data);
		status = 1;
	}
    pthread_mutex_unlock(&philo->mtx->death);
    return (status);
}


int	check_death(t_philo *philo)
{
    if (!check_must_eat(philo->data))
        return (1);
    if (check_philo_died(philo))
        return (1);
    if (check_time_to_die(philo))
        return (1);
    return (0);
}