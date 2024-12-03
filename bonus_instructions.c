/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:07:35 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 15:26:09 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	swap_lst(t_list **a);
static void	rotate_lst(t_list **a, int reversed);

void	swap(t_list **a, t_list **b, t_pile pile)
{
	if (pile == A)
		swap_lst(a);
	else if (pile == B)
		swap_lst(b);
	else if (pile == BOTH)
	{
		swap_lst(a);
		swap_lst(b);
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
	}
	else if (pile == B)
	{
		if (a == NULL || *a == NULL)
			return ;
		ft_lstinsert(b, 0, ft_lstpop(a, 0));
	}
}

void	rotate(t_list **a, t_list **b, int reversed, t_pile pile)
{
	if (pile == A)
		rotate_lst(a, reversed);
	else if (pile == B)
		rotate_lst(b, reversed);
	else if (pile == BOTH)
	{
		rotate_lst(a, reversed);
		rotate_lst(b, reversed);
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
