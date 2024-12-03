/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:52:00 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/28 10:09:37 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*previous;
	int				index;
	int				median;
	struct s_list	*target;
	int				cost;
}	t_list;

t_list	*ft_lstnew(int value);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstjoin(t_list *a, t_list *b);
int		ft_lstis_sorted(t_list *lst);

t_list	*ft_lstpop(t_list **lst, int index);
t_list	*ft_lstinsert(t_list **lst, int index, t_list *new);

t_list	*int_array_to_list(int *a, int len);
int		ft_lstget_index_of_max(t_list *lst);
t_list	*ft_lstget_min(t_list *lst);
void	ft_lstrecalculate_index(t_list *lst);
t_list	*get_smallest_target(t_list *lst, int value);
t_list	*get_biggest_target(t_list *lst, int value);
t_list	*get_cheapest(t_list *lst);

#endif
