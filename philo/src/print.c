/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/09/12 18:27:56 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/12 18:27:56 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	lock_and_print(int id, char *mess, t_data *data)
{
	pthread_mutex_lock(&data->mtx.death);
	pthread_mutex_lock(&data->mtx.print);
	if (data->end_simu == false)
	{	

		printf("%lld ", get_time_ms() - data->t_start);
		printf("%d ", id + 1);
		printf("%s\n", mess);
	}
	pthread_mutex_unlock(&data->mtx.print);
	pthread_mutex_unlock(&data->mtx.death);
}

void	lock_and_print_err(char *ft_name, pthread_mutex_t *mtx_print)
{
	pthread_mutex_lock(mtx_print);
	write(2, "Error: ", 7);
	write(2, ft_name, ft_strlen(ft_name));
	write(2, " failed !\n ", 10);
	pthread_mutex_unlock(mtx_print);
}
