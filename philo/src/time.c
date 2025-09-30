/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:37:27 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/30 00:05:44 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long usec, t_philo *philo)
{
	long start;

	start = get_time_ms();
	while ((get_time_ms() - start) * 1000 < usec)
	{
        (void)philo;
        // if (check_death(philo) == true)
        //     break;
		usleep(50);
	}
}

long long	get_interval_ms(long long start, long long end)
{
	return (end - start);
}

long long	get_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}
