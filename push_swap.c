/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:25:13 by dzurita           #+#    #+#             */
/*   Updated: 2024/01/02 12:38:53 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		start;

	a = NULL;
	b = NULL;
	start = 1;
	if (ac == 1)
		return (0);
	if (av[1] == NULL || av[1][0] == '\0')
		ft_show_error(av);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		start = 0;
	}
	check_errors(av, start);
	ft_add_values(&a, av, start);
	if (start == 0)
		free_split_result(av);
	the_sort(&a, &b);
	free_stack(&a);
}
