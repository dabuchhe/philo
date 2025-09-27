/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:48:17 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/04 23:48:17 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/****************************************************************************/
/*                                INCLUDE									*/
/****************************************************************************/
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

/****************************************************************************/
/*                                DEFINE									*/
/****************************************************************************/
// # define C_SPACE ' '

/****************************************************************************/
/*                                ENUM										*/
/****************************************************************************/
typedef enum e_status
{
    NO_ERROR,
	MALLOC_FAIL,
	INVALID_SYNTAX,
    PTHREAD_ERROR,
} t_status;

/****************************************************************************/
/*                                STRUCT									*/
/****************************************************************************/

typedef struct  s_mutex
{
    pthread_mutex_t *fork;
    pthread_mutex_t death;
    pthread_mutex_t print;
}   t_mutex;

typedef struct s_philo
{
    int             id;
    pthread_t       thread;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
    long long       t_last_eat;
    struct s_mutex  *mtx;
    struct s_data   *data;
}   t_philo;

typedef struct s_data
{
    int             nb_philo;
    int             t_die;
    int             t_eat;
    int             t_sleep;
    int             nb_eat;
    long long       t_start;
    long long       t_interval;
    bool            philo_died;
    t_philo         *philo;
    t_mutex         mtx;
}   t_data;

/****************************************************************************/
/*                                FUNCTIONS									*/
/****************************************************************************/
//  data.c
int	                init_all(char **av, t_data *data);
//  error.c
int	                invalid_syntax(t_data *data);
int	                malloc_fail(t_data *data);
int                 pthread_create_failed(t_data *data);

//  free.c
void                free_philo(t_philo *philo);
void                free_data(t_data *data);

//  parsing.c
bool	            arg_is_valid(int ac, char **av); // return false if not valid
int	                atoi_secure(char *str); // return -1 if not a num valid (overflow or neg)

//  philo.c
void                free_philo(t_philo *philo);

//  print.c
void                print_all(t_data *data);

//  routine.c
void	            *routine(void *arg);
int	                launch_routine(t_data *data);


long long	get_time_ms(void);
void	lock_and_print(int id, char *mess, t_data *data);
void    ft_usleep(long usec, t_philo *philo);
void	lock_and_print_err(char *ft_name, pthread_mutex_t *mtx_print);

//  utils.c
int ft_strlen(char *str);

//  wrapper.c
int	w_pthread_mutex_unlock(pthread_mutex_t *mutex, t_data *data);
int	w_pthread_mutex_lock(pthread_mutex_t *mutex, t_data *data);
int	w_pthread_mutex_init(pthread_mutex_t *mutex, t_data *data);
int	w_pthread_mutex_destroy(pthread_mutex_t *mutex, t_data *data);
int	w_pthread_create(pthread_t *thread, t_philo *philo, t_data *data);
int	w_pthread_join(pthread_t *thread, t_data *data);

#endif