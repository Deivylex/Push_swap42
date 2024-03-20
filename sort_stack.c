/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:50:55 by dzurita           #+#    #+#             */
/*   Updated: 2024/01/30 11:59:58 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **node_a, t_stack **node_b, t_stack *rf_node)
{
	while (*node_a != rf_node && *node_b != rf_node->target_node)
		ra_rb_rr(node_a, node_b, 3);
	current_index(*node_a);
	current_index(*node_b);
}

void	rev_rotate_both(t_stack **node_a, t_stack **node_b, t_stack *rf_node)
{
	while (*node_b != rf_node->target_node && *node_a != rf_node)
		rra_rrb_rrr(node_a, node_b, 3);
	current_index(*node_a);
	current_index(*node_b);
}

void	moving_to_node_b(t_stack **node_a, t_stack **node_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*node_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(node_a, node_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(node_a, node_b, cheapest_node);
	prep_for_push(node_a, node_b, cheapest_node, 'a');
	prep_for_push(node_b, node_a, cheapest_node->target_node, 'b');
	pa_pb(node_a, node_b, 2);
}

void	moving_to_node_a(t_stack **node_a, t_stack **node_b)
{
	prep_for_push(node_a, node_b, (*node_b)->target_node, 'a');
	pa_pb(node_a, node_b, 1);
}

void	the_sort(t_stack **node_a, t_stack **node_b)
{
	int	len_a;

	len_a = stack_len(*node_a);
	if (len_a-- > 3 && !sorted(*node_a))
		pa_pb(node_a, node_b, 2);
	if (len_a-- > 3 && !sorted(*node_a))
		pa_pb(node_a, node_b, 2);
	while (len_a-- > 3 && !sorted(*node_a))
	{
		init_nodes_a(*node_a, *node_b);
		moving_to_node_b(node_a, node_b);
	}
	sort_three(node_a, node_b);
	while (*node_b)
	{
		init_nodes_b(*node_a, *node_b);
		moving_to_node_a(node_a, node_b);
	}
	current_index(*node_a);
	final_check(node_a, node_b);
}
