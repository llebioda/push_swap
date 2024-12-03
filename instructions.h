/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:44:44 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 15:11:51 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H
# include "ft_list.h"

typedef enum e_pile
{
	NONE,
	A,
	B,
	BOTH
}	t_pile;

void	swap(t_list **a, t_list **b, t_pile pile);
void	push(t_list **a, t_list **b, t_pile pile);
void	rotate(t_list **a, t_list **b, int reversed, t_pile pile);

#endif
