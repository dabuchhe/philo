/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
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

int	dying(t_philo *philo)
{
	if (philo->t_last_eat - philo->data->t_start > philo->data->t_die)
	{
		w_pthread_mutex_lock(&philo->mtx->death, philo->data);
		philo->data->philo_died = true;
		lock_and_print(philo->id, "died", philo->data);
		w_pthread_mutex_unlock(&philo->mtx->death, philo->data);
		return (1);
	}
	return (0);
}

void	thinking(t_philo *philo)
{
	lock_and_print(philo->id, "is thinking", philo->data);
	ft_usleep((philo->data->t_eat + philo->data->t_sleep + 100) * 1000, philo);
}

void	sleeping(t_philo *philo)
{
	lock_and_print(philo->id, "is sleeping", philo->data);
	ft_usleep(philo->data->t_sleep * 1000, philo);
}


void	eating(t_philo *philo)
{
	w_pthread_mutex_lock(philo->l_fork, philo->data);
	lock_and_print(philo->id, "as taken a fork", philo->data);
	w_pthread_mutex_lock(philo->r_fork, philo->data);
	lock_and_print(philo->id, "as taken a fork", philo->data);
	lock_and_print(philo->id, "is eating", philo->data);
	philo->t_last_eat = get_time_ms();
	ft_usleep(philo->data->t_eat * 1000, philo);
	w_pthread_mutex_unlock(philo->l_fork, philo->data);
	w_pthread_mutex_unlock(philo->r_fork, philo->data);
}

void	*routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	eating(philo);
	sleeping(philo);
	thinking(philo);
	return (NULL);
}

void    ft_usleep(long usec, t_philo *philo)
{
    long start;
    
    start = get_time_ms();
    while ((get_time_ms() - start) * 1000 < usec)
    {
        if (dying(philo))
            break;
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

// int	launch_routine(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	data->t_start = get_time_ms();
// 	while (i < data->nb_philo)
// 	{
// 			w_pthread_create(&data->philo[i].thread, &data->philo[i], data);
// 			i++;
// 	}
// 	// check_death();
// 	// exit_launch; (join + destroy)
// 	return (0);
// }

// void *routine(void *args)
// {
//     t_philo *philo = (t_philo *)args;

//     if (philo->id % 2 == 0) // petit décalage pour éviter deadlock
//         usleep(500);

//     while (!philo->data->philo_died)
//     {
//         eating(philo);
//         sleeping(philo);
//         thinking(philo);
//     }
//     return (NULL);
// }

// int check_death(t_data *data)
// {
//     int i;

//     while (!data->philo_died)
//     {
//         i = 0;
//         while (i < data->nb_philo)
//         {
//             if (get_time_ms() - data->philo[i].t_last_eat > data->t_die)
//             {
//                 pthread_mutex_lock(&data->mtx->death);
//                 if (!data->philo_died) // double protection
//                 {
//                     data->philo_died = true;
//                     lock_and_print(data->philo[i].id, "died", data);
//                 }
//                 pthread_mutex_unlock(&data->mtx->death);
//                 return (1);
//             }
//             i++;
//         }
//         usleep(1000); // évite de consommer 100% CPU
//     }
//     return (0);
// }

// int launch_routine(t_data *data)
// {
//     int i;

//     data->t_start = get_time_ms();
//     i = 0;
//     while (i < data->nb_philo)
//     {
//         data->philo[i].t_last_eat = data->t_start;
//         pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
//         i++;
//     }
//     check_death(data);
//     exit_launch(data);
//     return (0);
// }

// int exit_launch(t_data *data)
// {
//     int i;

//     i = 0;
//     while (i < data->nb_philo)
//     {
//         pthread_join(data->philo[i].thread, NULL);
//         i++;
//     }
//     i = 0;
//     while (i < data->nb_philo)
//     {
//         pthread_mutex_destroy(data->philo[i].l_fork);
//         i++;
//     }
//     pthread_mutex_destroy(&data->mtx->death);
//     return (0);
// }