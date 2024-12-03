/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:24:26 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/29 10:25:05 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_list.h"
#include "instructions.h"

int		execute(t_list **a, t_list **b, char *buf, int len);
int		is_valid_char(char c);
t_pile	get_pile(char c, char *instruction);
int		flush(t_list *b, char *c, int return_value);

int	check_instructions(t_list **a)
{
	t_list	*b;
	char	c;
	char	buf[4];
	int		i;

	b = NULL;
	buf[3] = '\0';
	i = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (i < 2 || i > 3 || execute(a, &b, buf, i) == 0)
				return (flush(b, &c, -1));
			i = 0;
		}
		else if (i >= 4 || is_valid_char(c) == 0)
			return (flush(b, &c, -1));
		else
			buf[i++] = c;
	}
	if (b != NULL)
		return (flush(b, &c, 0));
	return (ft_lstis_sorted(*a));
}

int	execute(t_list **a, t_list **b, char *buf, int len)
{
	if (len == 2)
	{
		if (buf[0] == 's' && get_pile(buf[1], buf) != NONE)
		{
			swap(a, b, get_pile(buf[1], buf));
			return (1);
		}
		if (buf[0] == 'p' && get_pile(buf[1], NULL) != NONE)
		{
			push(a, b, get_pile(buf[1], NULL));
			return (1);
		}
		if (buf[0] == 'r' && get_pile(buf[1], buf) != NONE)
		{
			rotate(a, b, 0, get_pile(buf[1], buf));
			return (1);
		}
	}
	else if (len == 3 && buf[0] == 'r' && buf[1] == 'r'
		&& get_pile(buf[2], buf) != NONE)
	{
		rotate(a, b, 1, get_pile(buf[2], buf));
		return (1);
	}
	return (0);
}

int	is_valid_char(char c)
{
	if (c == 'a' || c == 'b' || c == 's' || c == 'p' || c == 'r' || c == '\n')
		return (1);
	return (0);
}

t_pile	get_pile(char c, char *instruction)
{
	if (c == 'a')
		return (A);
	if (c == 'b')
		return (B);
	if (instruction != NULL && c == *instruction)
		return (BOTH);
	return (NONE);
}

int	flush(t_list *b, char *c, int return_value)
{
	ft_lstclear(&b);
	if (*c == '\n')
		return (return_value);
	while (read(0, c, 1) > 0)
	{
		if (*c == '\n')
			return (return_value);
	}
	return (return_value);
}
