/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:01:23 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 15:35:03 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;

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
	solve(&a);
	ft_lstclear(&a);
	return (0);
}
