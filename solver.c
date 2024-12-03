/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <lowanlebioda@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:45:37 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 15:38:02 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void	sort_three(t_list **a);
void	move_node_to(t_list **a, t_list **b, t_pile pile);
void	move_min_to_top(t_list **a);

void	solve(t_list **a)
{
	t_list	*b;
	int		size;

	if (a == NULL || *a == NULL)
		return ;
	if (ft_lstis_sorted(*a) == 1)
		return ;
	b = NULL;
	size = ft_lstsize(*a);
	if (size >= 5)
	{
		push(a, &b, B);
		push(a, &b, B);
		size -= 2;
	}
	while (size > 3)
	{
		move_node_to(a, &b, B);
		size--;
	}
	sort_three(a);
	while (b != NULL)
		move_node_to(a, &b, A);
	move_min_to_top(a);
}

void	sort_three(t_list **a)
{
	int	max_index;

	max_index = ft_lstget_index_of_max(*a);
	if (max_index == 0)
		rotate(a, NULL, 0, A);
	else if (max_index == 1)
		rotate(a, NULL, 1, A);
	if (ft_lstis_sorted(*a) == 0)
		swap(a, NULL, A);
}

void	move_min_to_top(t_list **a)
{
	t_list	*min_lst;
	int		reversed;
	int		i;

	ft_lstrecalculate_index(*a);
	min_lst = ft_lstget_min(*a);
	reversed = 0;
	i = min_lst->index;
	if (i > min_lst->median)
	{
		reversed = 1;
		i = ft_lstsize(*a) - min_lst->index;
	}
	while (i > 0)
	{
		rotate(a, NULL, reversed, A);
		i--;
	}
}
