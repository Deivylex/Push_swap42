/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:27:26 by dzurita           #+#    #+#             */
/*   Updated: 2024/01/30 13:57:42 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_stack *node_a, t_stack *node_b)
{
	t_stack	*cur_b;
	t_stack	*target_node;
	long	bt_match;

	while (node_a != NULL)
	{
		bt_match = LONG_MIN;
		cur_b = node_b;
		while (cur_b != NULL)
		{
			if (cur_b->nbr < node_a->nbr && cur_b->nbr > bt_match)
			{
				bt_match = cur_b->nbr;
				target_node = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (bt_match == LONG_MIN)
			node_a->target_node = find_max_stack(node_b);
		else
			node_a->target_node = target_node;
		node_a = node_a->next;
	}
}

void	cost_analysis_a(t_stack *node_a, t_stack *node_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(node_a);
	len_b = stack_len(node_b);
	while (node_a != NULL)
	{
		node_a->push_cost = node_a->index;
		if (!(node_a->above_median))
			node_a->push_cost = len_a - (node_a->index);
		if (node_a->target_node->above_median)
			node_a->push_cost += node_a->target_node->index;
		else
			node_a->push_cost += len_b - (node_a->target_node->index);
		node_a = node_a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_nodes_a(t_stack *node_a, t_stack *node_b)
{
	current_index(node_a);
	current_index(node_b);
	set_target(node_a, node_b);
	cost_analysis_a(node_a, node_b);
	set_cheapest(node_a);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
