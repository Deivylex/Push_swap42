/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_final_step.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:17:35 by dzurita           #+#    #+#             */
/*   Updated: 2024/01/30 12:25:19 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min_stack(t_stack *stack)
{
	long	min;
	t_stack	*smaller;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			smaller = stack;
		}
		stack = stack->next;
	}
	return (smaller);
}

int	ft_index_min(t_stack *stack)
{
	int	idx;

	idx = 0;
	while (stack->nbr != find_min(stack) && (stack)->next != NULL)
	{
		idx++;
		stack = stack->next;
	}
	return (idx);
}

void	final_check(t_stack **node_a, t_stack **node_b)
{
	int	idx_min;

	if ((*node_a)->nbr != find_min(*node_a))
	{
		idx_min = ft_index_min(*node_a);
		if (idx_min <= stack_len(*node_a) / 2)
		{
			ra_rb_rr(node_a, node_b, 1);
			return (final_check(node_a, node_b));
		}
		else
		{
			rra_rrb_rrr(node_a, node_b, 1);
			return (final_check(node_a, node_b));
		}
	}
}

void	set_target_b(t_stack *node_a, t_stack *node_b)
{
	t_stack	*cur_a;
	t_stack	*target_node;
	long	bt_match;

	while (node_b != NULL)
	{
		bt_match = LONG_MAX;
		cur_a = node_a;
		while (cur_a != NULL)
		{
			if (cur_a->nbr > node_b->nbr && cur_a->nbr < bt_match)
			{
				bt_match = cur_a->nbr;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (bt_match == LONG_MAX)
			node_b->target_node = find_min_stack(node_a);
		else
			node_b->target_node = target_node;
		node_b = node_b->next;
	}
}

void	init_nodes_b(t_stack *node_a, t_stack *node_b)
{
	current_index(node_a);
	current_index(node_b);
	set_target_b(node_a, node_b);
}
