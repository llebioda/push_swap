/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:07:35 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 10:45:11 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	swap_lst(t_list **a);
static void	rotate_lst(t_list **a, int reversed);

void	swap(t_list **a, t_list **b, t_pile pile)
{
	if (pile == A)
	{
		swap_lst(a);
		write(1, "sa\n", 3);
	}
	else if (pile == B)
	{
		swap_lst(b);
		write(1, "sb\n", 3);
	}
	else if (pile == BOTH)
	{
		swap_lst(a);
		swap_lst(b);
		write(1, "ss\n", 3);
	}
}

static void	swap_lst(t_list **a)
{
	t_list	*ls1;
	t_list	*ls2;

	if (a == NULL || ft_lstsize(*a) <= 1)
		return ;
	ls1 = (*a);
	ls2 = ls1->next;
	*a = ls2;
	ls2->previous = NULL;
	ls1->previous = ls2;
	ls1->next = ls2->next;
	ls2->next = ls1;
	if (ls1->next != NULL)
		ls1->next->previous = ls1;
}

void	push(t_list **a, t_list **b, t_pile pile)
{
	if (pile == A)
	{
		if (b == NULL || *b == NULL)
			return ;
		ft_lstinsert(a, 0, ft_lstpop(b, 0));
		write(1, "pa\n", 3);
	}
	else if (pile == B)
	{
		if (a == NULL || *a == NULL)
			return ;
		ft_lstinsert(b, 0, ft_lstpop(a, 0));
		write(1, "pb\n", 3);
	}
}

void	rotate(t_list **a, t_list **b, int reversed, t_pile pile)
{
	if (pile == A)
	{
		rotate_lst(a, reversed);
		if (reversed == 1)
			write(1, "rra\n", 4);
		else
			write(1, "ra\n", 3);
	}
	else if (pile == B)
	{
		rotate_lst(b, reversed);
		if (reversed == 1)
			write(1, "rrb\n", 4);
		else
			write(1, "rb\n", 3);
	}
	else if (pile == BOTH)
	{
		rotate_lst(a, reversed);
		rotate_lst(b, reversed);
		if (reversed == 1)
			write(1, "rrr\n", 4);
		else
			write(1, "rr\n", 3);
	}
}

static void	rotate_lst(t_list **lst, int reversed)
{
	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	if (reversed == 1)
		ft_lstinsert(lst, 0, ft_lstpop(lst, -1));
	else
		ft_lstinsert(lst, -1, ft_lstpop(lst, 0));
}
