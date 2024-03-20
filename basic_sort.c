/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:38:26 by dzurita           #+#    #+#             */
/*   Updated: 2024/01/30 14:04:16 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*current;

	current = stack->next;
	max = stack->nbr;
	while (current != NULL)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

void	sort_three(t_stack **node_a, t_stack **node_b)
{
	int	temp;

	if (sorted(*node_a))
		return ;
	temp = find_max(*node_a);
	if ((*node_a)->nbr > (*node_a)->next->nbr && !((*node_a)->next->next))
		sa_sb_ss(node_a, node_b, 1);
	else
	{
		if ((*node_a)->nbr == temp)
			ra_rb_rr(node_a, node_b, 1);
		if ((*node_a)->nbr > (*node_a)->next->nbr)
			sa_sb_ss(node_a, node_b, 1);
		if ((*node_a)->nbr > (*node_a)->next->next->nbr)
			rra_rrb_rrr(node_a, node_b, 1);
		if ((*node_a)->next->nbr > (*node_a)->next->next->nbr)
		{
			rra_rrb_rrr(node_a, node_b, 1);
			sa_sb_ss(node_a, node_b, 1);
		}
	}
}

void	current_index(t_stack *stack)
{
	int	idx;
	int	median;

	if (!stack)
		return ;
	idx = 0;
	median = stack_len(stack) / 2;
	while (stack != 0)
	{
		stack->index = idx;
		if (idx <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		idx++;
	}
}

t_stack	*find_max_stack(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	prep_for_push(t_stack **stack, t_stack **node_b,
		t_stack *rf_node, char node)
{
	while (*stack != rf_node)
	{
		if (node == 'a')
		{
			if (rf_node->above_median)
				ra_rb_rr(stack, node_b, 1);
			else
				rra_rrb_rrr(stack, node_b, 1);
		}
		else if (node == 'b')
		{
			if (rf_node->above_median)
				ra_rb_rr(node_b, stack, 2);
			else
				rra_rrb_rrr(node_b, stack, 2);
		}
	}
}
