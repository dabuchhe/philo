/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/09/12 19:32:27 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/12 19:32:27 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	w_pthread_join(pthread_t *thread, t_data *data)
{
	int err;

	err = pthread_join(*thread, NULL);
	if (err)
	{
		// end_routine();
		lock_and_print_err("pthread_join", &data->mtx.print);
	}
	return (err);
}

int	w_pthread_create(pthread_t *thread, t_philo *philo, t_data *data)
{
	int err;

	err = pthread_create(thread, NULL, routine, philo);
	if (err)
		lock_and_print_err("pthread_create", &data->mtx.print);
	return (err);
}

int	w_pthread_mutex_destroy(pthread_mutex_t *mutex, t_data *data)
{
	int err;

	err = pthread_mutex_destroy(mutex);
	if (err)
		lock_and_print_err("pthread_mutex_destroy", &data->mtx.print);
	return (err);
}

int	w_pthread_mutex_init(pthread_mutex_t *mutex, t_data *data)
{
	int err;

	err = pthread_mutex_init(mutex, NULL);
	if (err)
		lock_and_print_err("pthread_mutex_init", &data->mtx.print);
	return (err);
}

int	w_pthread_mutex_lock(pthread_mutex_t *mutex, t_data *data)
{
	int err;

	err = pthread_mutex_lock(mutex);
	if (err)
		lock_and_print_err("pthread_mutex_lock", &data->mtx.print);
	return (err);
}

int	w_pthread_mutex_unlock(pthread_mutex_t *mutex, t_data *data)
{
	int err;

	err = pthread_mutex_unlock(mutex);
	if (err)
		lock_and_print_err("pthread_mutex_unlock", &data->mtx.print);
	return (err);
}
