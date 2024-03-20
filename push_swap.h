/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:46:22 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/01 14:59:52 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

void		check_errors(char **av, int start);
void		ft_add_values(t_stack **a, char **av, int start);
int			stack_len(t_stack *stack);

void		ft_rotate(t_stack **stack);
void		ft_swap(t_stack **stack);
void		rot_rev(t_stack **stack);
void		push(t_stack **node_a, t_stack **node_b);

void		sort_three(t_stack **node_a, t_stack **node_b);
int			find_max(t_stack *stack);
int			find_min(t_stack *stack);
int			ft_index_min(t_stack *stack);

void		sa_sb_ss(t_stack **node_a, t_stack **node_b, int type);
void		pa_pb(t_stack **node_a, t_stack **node_b, int type);
void		ra_rb_rr(t_stack **node_a, t_stack **node_b, int type);
void		rra_rrb_rrr(t_stack **node_a, t_stack **node_b, int type);
int			sorted(t_stack *stack);
void		t_add_back(t_stack **stack, t_stack *new);

void		init_nodes_a(t_stack *node_a, t_stack *node_b);
void		the_sort(t_stack **a, t_stack **b);
void		current_index(t_stack *stack);
t_stack		*find_max_stack(t_stack *stack);
void		cost_analysis_a(t_stack *node_a, t_stack *node_b);

void		moving_to_node_b(t_stack **node_a, t_stack **node_b);
void		prep_for_push(t_stack **stack, t_stack **node_b,
				t_stack *rf_node, char node);
void		rev_rotate_both(t_stack **node_a, t_stack **node_b, t_stack *rf);
void		rotate_both(t_stack **node_a, t_stack **node_b, t_stack *rf_node);
t_stack		*get_cheapest(t_stack *stack);
void		moving_to_node_a(t_stack **node_a, t_stack **node_b);

void		init_nodes_b(t_stack *node_a, t_stack *node_b);
void		final_check(t_stack **node_a, t_stack **node_b);
void		set_sec(t_stack *node_a);
void		set_cheapest(t_stack *stack);
void		free_stack(t_stack **stack);
void		ft_show_error(char **node_a);
void		free_split_result(char **split_result);

#endif
