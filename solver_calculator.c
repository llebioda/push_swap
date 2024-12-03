/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:45:37 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/27 16:56:16 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_smallest_targets(t_list *a, t_list *b)
{
	if (a == NULL || b == NULL)
		return ;
	while (a != NULL)
	{
		a->target = get_smallest_target(b, a->value);
		a = a->next;
	}
}

void	calculate_biggest_targets(t_list *a, t_list *b)
{
	if (a == NULL || b == NULL)
		return ;
	while (b != NULL)
	{
		b->target = get_biggest_target(a, b->value);
		b = b->next;
	}
}

void	calculate_cost(t_list *a, t_list *b)
{
	int	size_a;
	int	size_b;

	if (a == NULL)
		return ;
	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (a != NULL)
	{
		a->cost = INT_MAX;
		if (a->target != NULL)
		{
			if (a->index <= a->median)
				a->cost = a->index;
			else
				a->cost = size_a - a->index;
			if (a->target->index <= a->target->median)
				a->cost += a->target->index;
			else
				a->cost += size_b - a->target->index;
		}
		a = a->next;
	}
}
