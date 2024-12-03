/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:54:12 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 09:48:51 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstrecalculate_index(t_list *lst)
{
	int	i;
	int	median;

	if (lst == NULL)
		return ;
	median = ft_lstsize(lst) / 2;
	i = 0;
	while (lst != NULL)
	{
		lst->index = i;
		lst->median = median;
		lst = lst->next;
		i++;
	}
}

t_list	*get_smallest_target(t_list *lst, int value)
{
	t_list	*smallest_target;
	t_list	*max_target;
	int		max_value;

	if (lst == NULL)
		return (NULL);
	smallest_target = NULL;
	max_target = lst;
	max_value = lst->value;
	while (lst != NULL)
	{
		if (lst->value < value && (smallest_target == NULL
				|| lst->value > smallest_target->value))
			smallest_target = lst;
		if (lst->value > max_value)
		{
			max_value = lst->value;
			max_target = lst;
		}
		lst = lst->next;
	}
	if (smallest_target != NULL)
		return (smallest_target);
	return (max_target);
}

t_list	*get_biggest_target(t_list *lst, int value)
{
	t_list	*biggest_target;
	t_list	*min_target;
	int		min_value;

	if (lst == NULL)
		return (NULL);
	biggest_target = NULL;
	min_target = lst;
	min_value = lst->value;
	while (lst != NULL)
	{
		if (lst->value > value && (biggest_target == NULL
				|| lst->value < biggest_target->value))
			biggest_target = lst;
		if (lst->value < min_value)
		{
			min_value = lst->value;
			min_target = lst;
		}
		lst = lst->next;
	}
	if (biggest_target != NULL)
		return (biggest_target);
	return (min_target);
}

t_list	*get_cheapest(t_list *lst)
{
	t_list	*cheapest;

	if (lst == NULL)
		return (NULL);
	cheapest = lst;
	while (lst != NULL)
	{
		if (lst->cost < cheapest->cost)
			cheapest = lst;
		lst = lst->next;
	}
	return (cheapest);
}
