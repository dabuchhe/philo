/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:09:44 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/12 18:09:44 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	invalid_syntax(t_data *data)
// {
// 	free_data(data);
// 	data->err = INVALID_SYNTAX;
// 	printf("Error : Invalid Syntax");
// 	return (data->err);
// }

// int	malloc_fail(t_data *data)
// {
// 	free_data(data);
// 	data->err = MALLOC_FAIL;
// 	printf("Error : Malloc Failed");
// 	return (data->err);
// }

// int	pthread_create_failed(t_data *data)
// {
// 	free_data(data);
// 	data->err = PTHREAD_ERROR;
// 	printf("Error : Pthread failed to create");
// 	return (data->err);
// }

// int	error_handler(t_data *data)
// {
// 	if (data->err == MALLOC_FAIL)
// 		return (malloc_fail(data));
// 	if (data->err == INVALID_SYNTAX)
// 		return (invalid_syntax(data));
// 	if (data->err == PTHREAD_ERROR)
// 		return (pthread_create_failed(data));
// 	return (data->err);
// }
