/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:01:23 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 12:33:21 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_checker.h"

static t_list	*get_parsed_numbers(const char *numbers);
static int		*parse_numbers(char **num_splited, int len);

t_list	*parse_args(int len, char **argv)
{
	t_list	*a;
	t_list	*temp;
	int		i;

	if (check_args(len, argv) == 0)
		return (NULL);
	a = NULL;
	i = 0;
	while (i < len)
	{
		temp = get_parsed_numbers(argv[i++]);
		if (temp == NULL)
			return (NULL);
		if (check_duplicated(a, temp) == 1)
		{
			ft_lstclear(&a);
			ft_lstclear(&temp);
			return (NULL);
		}
		a = ft_lstjoin(a, temp);
	}
	return (a);
}

static t_list	*get_parsed_numbers(const char *numbers)
{
	char	**num_splited;
	t_list	*lst;
	int		*num;
	int		len;

	num_splited = ft_split(numbers, ' ');
	if (num_splited == NULL)
		return (NULL);
	len = 0;
	while (num_splited[len])
		len++;
	num = parse_numbers(num_splited, len);
	lst = int_array_to_list(num, len);
	free(num);
	while (--len >= 0)
		free(num_splited[len]);
	free(num_splited);
	return (lst);
}

static int	*parse_numbers(char **num_splited, int len)
{
	int	*numbers;
	int	i;

	numbers = ft_calloc(len, sizeof(int));
	if (numbers == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (check_int_overflow(num_splited[i]) == 0)
		{
			free(numbers);
			return (NULL);
		}
		numbers[i] = ft_atoi(num_splited[i]);
		i++;
	}
	return (numbers);
}
