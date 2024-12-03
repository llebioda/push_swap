/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <lowanlebioda@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:54:12 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 13:27:42 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstpop(t_list **lst, int index)
{
	t_list	*current;
	int		i;

	if (!lst || *lst == NULL || (index < 0 && ft_lstsize(*lst) + index < 0))
		return (NULL);
	current = *lst;
	if (index < 0)
		index = ft_lstsize(current) + index;
	if (index == 0)
		*lst = (*lst)->next;
	i = 0;
	while (i < index)
	{
		if (current->next == NULL)
			return (NULL);
		current = current->next;
		i++;
	}
	if (current->next != NULL)
		current->next->previous = current->previous;
	if (current->previous != NULL)
		current->previous->next = current->next;
	current->next = NULL;
	current->previous = NULL;
	return (current);
}

t_list	*ft_lstinsert(t_list **lst, int index, t_list *new)
{
	t_list	*current;
	int		i;

	if (!lst || !new || (index < 0 && ft_lstsize(*lst) + index < 0))
		return (*lst);
	current = *lst;
	if (index < 0)
		index = ft_lstsize(current) + index + 1;
	if (index == 0)
	{
		new->next = current;
		if (current != NULL)
			current->previous = new;
		*lst = new;
		return (new);
	}
	i = 1;
	while (i++ < index && current->next != NULL)
		current = current->next;
	new->previous = current;
	new->next = current->next;
	current->next = new;
	if (new->next != NULL)
		new->next->previous = new;
	return (*lst);
}

t_list	*int_array_to_list(int *a, int len)
{
	t_list	*lst;
	t_list	*current;
	int		i;

	if (a == NULL || len <= 0)
		return (NULL);
	lst = NULL;
	i = len - 1;
	while (i >= 0)
	{
		current = ft_lstnew(a[i]);
		if (current == NULL)
		{
			ft_lstclear(&lst);
			return (NULL);
		}
		ft_lstinsert(&lst, 0, current);
		i--;
	}
	return (lst);
}

int	ft_lstget_index_of_max(t_list *lst)
{
	int	max_index;
	int	max;
	int	i;

	if (lst == NULL)
		return (-1);
	if (lst->next == NULL)
		return (0);
	max_index = 0;
	max = lst->value;
	i = 1;
	lst = lst->next;
	while (lst != NULL)
	{
		if (lst->value > max)
		{
			max = lst->value;
			max_index = i;
		}
		i++;
		lst = lst->next;
	}
	return (max_index);
}

t_list	*ft_lstget_min(t_list *lst)
{
	t_list	*min_lst;
	int		min;

	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	min_lst = lst;
	min = lst->value;
	lst = lst->next;
	while (lst != NULL)
	{
		if (lst->value < min)
		{
			min_lst = lst;
			min = lst->value;
		}
		lst = lst->next;
	}
	return (min_lst);
}
