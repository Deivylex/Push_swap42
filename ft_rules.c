/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:28:31 by dzurita           #+#    #+#             */
/*   Updated: 2024/01/30 14:06:43 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*nodo1;
	t_stack	*nodo2;
	int		temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	nodo1 = *stack;
	nodo2 = nodo1->next;
	temp = nodo1->nbr;
	nodo1->nbr = nodo2->nbr;
	nodo2->nbr = temp;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	node1 = *stack;
	node2 = node1->next;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	*stack = node2;
	last_node->next = node1;
	node1->next = NULL;
}

void	rot_rev(t_stack **stack)
{
	t_stack	*node_l1;
	t_stack	*node_l2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	node_l1 = *stack;
	node_l2 = NULL;
	while (node_l1->next != NULL)
	{
		node_l2 = node_l1;
		node_l1 = node_l1->next;
	}
	node_l1->next = *stack;
	*stack = node_l1;
	node_l2->next = NULL;
}

void	push(t_stack **node_a, t_stack **node_b)
{
	t_stack	*push;

	if (*node_a == NULL && node_b == NULL)
		return ;
	push = *node_a;
	*node_a = (*node_a)->next;
	push->next = *node_b;
	*node_b = push;
}

int	sorted(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL || stack->next == NULL)
		return (1);
	current = stack;
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}
