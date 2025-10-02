/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dabuchhe <dabuchhe@student.42lyon.fr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/09/05 15:19:22 by dabuchhe          #+#    #+#             */
/*   Updated: 2025/09/05 15:19:22 by dabuchhe         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <philo.h>

int	atoi_secure(char *str)
{
	int	res;
	int	neg;
	int	i;

	res = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (INT_MAX - (str[i] - '0')) / 10)
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

static bool	is_numeric(char *av)
{
	int		i;
	bool	neg;

	neg = 1;
	i = 0;
	while (av[i] == ' ' || (av[i] > 9 && av[i] == 13))
		i++;
	while (av[i] == '+' || av[i] == '-')
	{
		if (av[i] == '-')
			neg *= -1;
		i++;
	}
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	arg_is_valid(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (false);
	i = 1;
	while (av[i])
	{
		if (!av[i])
			return (false);
		if (!is_numeric(av[i]))
			return (false);
		if (atoi_secure(av[i]) < 0)
			return (false);
		i++;
	}
	return (true);
}
