/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:58:32 by dzurita           #+#    #+#             */
/*   Updated: 2024/01/30 11:27:57 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb_ss(t_stack **node_a, t_stack **node_b, int type)
{
	if (type == 1)
	{
		ft_swap(node_a);
		write(1, "sa\n", 3);
	}
	if (type == 2)
	{
		ft_swap(node_b);
		write(1, "sa\n", 3);
	}
	if (type == 3)
	{
		ft_swap(node_a);
		ft_swap(node_b);
		write(1, "sa\n", 3);
	}
}

void	pa_pb(t_stack **node_a, t_stack **node_b, int type)
{
	if (type == 1)
	{
		push(node_b, node_a);
		write(1, "pa\n", 3);
	}
	if (type == 2)
	{
		push(node_a, node_b);
		write(1, "pb\n", 3);
	}
}

void	ra_rb_rr(t_stack **node_a, t_stack **node_b, int type)
{
	if (type == 1)
	{
		ft_rotate(node_a);
		write(1, "ra\n", 3);
	}
	if (type == 2)
	{
		ft_rotate(node_b);
		write(1, "rb\n", 3);
	}
	if (type == 3)
	{
		ft_rotate(node_a);
		ft_rotate(node_b);
		write(1, "rr\n", 3);
	}
}

void	rra_rrb_rrr(t_stack **node_a, t_stack **node_b, int type)
{
	if (type == 1)
	{
		rot_rev(node_a);
		write(1, "rra\n", 4);
	}
	if (type == 2)
	{
		rot_rev(node_b);
		write(1, "rrb\n", 4);
	}
	if (type == 3)
	{
		rot_rev(node_a);
		rot_rev(node_b);
		write(1, "rrr\n", 4);
	}
}
