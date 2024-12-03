/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <lowanlebioda@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:12 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/27 14:30:29 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_list.h"

t_list	*parse_args(int len, char **argv);
void	solve(t_list **a);

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
