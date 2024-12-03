/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:59:27 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/26 16:00:21 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	a;
	int	is_neg;

	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	is_neg = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			is_neg = 1;
		nptr++;
	}
	a = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		a = a * 10 + (*nptr - '0');
		nptr++;
	}
	if (is_neg == 1)
		return (-a);
	return (a);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	s;
	char	*c;
	size_t	i;

	if (nmemb > 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	s = nmemb * size;
	ptr = malloc(s);
	if (ptr == NULL)
		return (NULL);
	c = ptr;
	i = 0;
	while (i < s)
		c[i++] = 0;
	return (ptr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	r;

	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	r = *(unsigned char *)s1 - *(unsigned char *)s2;
	if (r > 0)
		return (1);
	if (r < 0)
		return (-1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
