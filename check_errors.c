/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:57:15 by dzurita           #+#    #+#             */
/*   Updated: 2024/01/30 11:08:02 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_parameters(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	return (0);
}

long long	ft_check_max_min(const char *nptr)
{
	int		sign;
	long	num;

	if (ft_strlen(nptr) > 14)
		return (99999999999999);
	while ((*nptr == ' ') || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	num = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

int	ft_duplicate(char **str, int start)
{
	int	i;
	int	j;

	i = start;
	j = start + 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j] != NULL)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_show_error(char **node_a)
{
	node_a = NULL;
	write(2, "Error\n", 6);
	exit(0);
}

void	check_errors(char **av, int start)
{
	long long	n;

	while (av[start])
	{
		if (ft_check_parameters(av[start]))
			ft_show_error(av);
		n = ft_check_max_min(av[start]);
		if (n > INT_MAX || n < INT_MIN)
			ft_show_error(av);
		if (ft_duplicate(av, start) == 1)
			ft_show_error(av);
		start++;
	}
}
