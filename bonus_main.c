/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:23:44 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 15:38:19 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_instructions(t_list **a);

int	handle_return(int r_val)
{
	if (r_val == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (r_val == 0)
		write(1, "KO\n", 3);
	else if (r_val == 1)
		write(1, "OK\n", 3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	int		r_val;

	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = parse_args(argc - 1, &(argv[1]));
	if (a == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	r_val = check_instructions(&a);
	ft_lstclear(&a);
	return (handle_return(r_val));
}
