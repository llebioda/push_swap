/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:01:23 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/26 15:45:16 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_checker.h"

int	check_args(int len, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && argv[i][j] != ' ')
			{
				if (!(argv[i][j] == '-' && (j == 0 || argv[i][j - 1] == ' ')
					&& argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int_overflow(const char *str)
{
	size_t	len;
	size_t	is_negative;

	if (str == NULL)
		return (0);
	is_negative = str[0] == '-';
	len = ft_strlen(str);
	if (len < 10 + is_negative)
		return (1);
	if (len > 10 + is_negative)
		return (0);
	if (is_negative)
		return (ft_strcmp(str, "-2147483648") <= 0);
	return (ft_strcmp(str, "2147483647") <= 0);
}

int	check_duplicated(t_list *a, t_list *b)
{
	t_list	*bb;

	if (a == NULL || b == NULL)
		return (0);
	while (a != NULL)
	{
		bb = b;
		while (bb != NULL)
		{
			if (a->value == bb->value)
				return (1);
			bb = bb->next;
		}
		a = a->next;
	}
	return (0);
}
