/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:09:23 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/06 12:19:23 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*t_new(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nbr = content;
	new_node->next = NULL;
	return (new_node);
}

void	t_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = *stack;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	ft_add_values(t_stack **stack, char **av, int start)
{
	int		num;
	t_stack	*temp;

	while (av[start])
	{
		num = ft_atoi(av[start]);
		temp = t_new(num);
		if (!temp)
			free_stack(stack);
		t_add_back(stack, temp);
		start++;
	}
}

int	stack_len(t_stack *stack)
{
	t_stack	*current;
	int		len;

	current = stack;
	len = 0;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*current;

	current = stack->next;
	min = stack->nbr;
	while (current != NULL)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}
