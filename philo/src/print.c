/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:27:56 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/12 18:27:56 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_and_print(int id, char *mess, t_data *data) // TODO: refacto with p_thread instead of data
{
	pthread_mutex_lock(&data->mtx.print);
	printf("%lld ", get_time_ms() - data->t_start);
	printf("%d ", id + 1);
	printf("%s\n", mess);
	pthread_mutex_unlock(&data->mtx.print);
}

void	lock_and_print_err(char *ft_name, pthread_mutex_t *mtx_print)
{
	pthread_mutex_lock(mtx_print);
	write(2, "Error: ", 7);
	write(2, ft_name, ft_strlen(ft_name));
	write(2, " failed !\n ", 10);
	pthread_mutex_unlock(mtx_print);
}

void	print_philo(t_data *data)
{
	int	i;

	i = 0;

	printf("+-----------------------+\n");
	printf("|	PHILO		|\n");
	printf("+-----------------------+\n");
	while (i < data->nb_philo)
	{
		printf("id \t= %d\n", data->philo[i].id);
		// printf("fork_l\t= %d\n", data->philo[i].fork_l);
		// printf("fork_r\t= %d\n", *(data->philo[i].fork_r));
		printf("\n\n");
		i++;
	}
}

void	print_data(t_data *data)
{
	printf("+-----------------------+\n");
	printf("|	DATA		|\n");
	printf("+-----------------------+\n");
	printf("nb_philo   \t= %d\n", data->nb_philo);
	printf("time_start\t= %lld\n", data->t_start);
	printf("time_to_die\t= %d\n", data->t_die);
	printf("time_to_eat   \t= %d\n", data->t_eat);
	printf("time_to_sleep\t= %d\n", data->t_sleep);
	printf("must_eat\t= %d\n", data->t_sleep);
	printf("\n\n");
}

void	print_all(t_data *data)
{
	pthread_mutex_lock(&(data->mtx.print));
	print_data(data);
	print_philo(data);
	pthread_mutex_unlock(&(data->mtx.print));

}
