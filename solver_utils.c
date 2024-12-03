/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:45:37 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 12:48:24 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void		calculate_smallest_targets(t_list *a, t_list *b);
void		calculate_biggest_targets(t_list *a, t_list *b);
void		calculate_cost(t_list *a, t_list *b);
static void	move_cheapest_to_b(t_list **a, t_list **b);
static void	move_cheapest_to_a(t_list **a, t_list **b);
static int	init_move_to_top(t_list *cheapest, t_list **a, t_list **b, int *ar);

void	move_node_to(t_list **a, t_list **b, t_pile pile)
{
	if (a == NULL || b == NULL || pile == BOTH)
		return ;
	ft_lstrecalculate_index(*a);
	ft_lstrecalculate_index(*b);
	if (pile == B)
	{
		calculate_smallest_targets(*a, *b);
		calculate_cost(*a, *b);
		move_cheapest_to_b(a, b);
	}
	else if (pile == A)
	{
		calculate_biggest_targets(*a, *b);
		calculate_cost(*b, *a);
		move_cheapest_to_a(a, b);
	}
}

static void	move_cheapest_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest;
	int		ar;
	int		br;

	if (a == NULL || b == NULL || *a == NULL)
		return ;
	cheapest = get_cheapest(*a);
	br = init_move_to_top(cheapest, a, b, &ar);
	while (ar == br && cheapest->index > 0 && cheapest->target->index > 0)
	{
		rotate(a, b, ar, BOTH);
		cheapest->index--;
		cheapest->target->index--;
	}
	while (cheapest->index > 0)
	{
		rotate(a, NULL, ar, A);
		cheapest->index--;
	}
	while (br != -1 && cheapest->target->index > 0)
	{
		rotate(NULL, b, br, B);
		cheapest->target->index--;
	}
	push(a, b, B);
}

static void	move_cheapest_to_a(t_list **a, t_list **b)
{
	t_list	*cheapest;
	int		ar;
	int		br;

	if (a == NULL || b == NULL || *b == NULL)
		return ;
	cheapest = get_cheapest(*b);
	ar = init_move_to_top(cheapest, b, a, &br);
	while (ar == br && cheapest->index > 0 && cheapest->target->index > 0)
	{
		rotate(a, b, br, BOTH);
		cheapest->index--;
		cheapest->target->index--;
	}
	while (cheapest->index > 0)
	{
		rotate(NULL, b, br, B);
		cheapest->index--;
	}
	while (ar != -1 && cheapest->target->index > 0)
	{
		rotate(a, NULL, ar, A);
		cheapest->target->index--;
	}
	push(a, b, A);
}

static int	init_move_to_top(t_list *cheapest, t_list **a, t_list **b, int *ar)
{
	int	br;

	*ar = 0;
	if (cheapest->index > cheapest->median)
	{
		*ar = 1;
		cheapest->index = ft_lstsize(*a) - cheapest->index;
	}
	if (cheapest->target == NULL)
		return (-1);
	br = 0;
	if (cheapest->target->index > cheapest->target->median)
	{
		br = 1;
		cheapest->target->index = ft_lstsize(*b) - cheapest->target->index;
	}
	return (br);
}
