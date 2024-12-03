/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:54:12 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 09:50:23 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstnew(int value)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->value = value;
	lst->next = NULL;
	lst->previous = NULL;
	lst->index = 0;
	lst->target = NULL;
	return (lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ls;
	t_list	*temp;

	ls = *lst;
	while (ls != NULL)
	{
		temp = ls->next;
		free(ls);
		ls = temp;
	}
	*lst = NULL;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstjoin(t_list *a, t_list *b)
{
	t_list	*t;

	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	t = a;
	while (t->next != NULL)
		t = t->next;
	t->next = b;
	b->previous = t;
	return (a);
}

int	ft_lstis_sorted(t_list *lst)
{
	int	previous_value;

	if (lst == NULL || lst->next == NULL)
		return (1);
	previous_value = lst->value;
	lst = lst->next;
	while (lst != NULL)
	{
		if (previous_value > lst->value)
			return (0);
		previous_value = lst->value;
		lst = lst->next;
	}
	return (1);
}
