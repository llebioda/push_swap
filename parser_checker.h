/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:29:38 by llebioda          #+#    #+#             */
/*   Updated: 2024/12/09 10:29:39 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_CHECKER_H
# define PARSER_CHECKER_H
# include "push_swap.h"

int		check_args(int len, char **argv);
int		check_int_overflow(const char *str);
int		check_duplicated(t_list *a, t_list *b);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

#endif
