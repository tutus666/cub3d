/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:22:29 by ataverni          #+#    #+#             */
/*   Updated: 2021/03/31 19:32:40 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(const char *s, char c)
{
	size_t	cmpt;

	cmpt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			cmpt++;
		while (*s != c && *s)
			s++;
	}
	return (cmpt);
}

static char	*ft_cpy(const char *s, char c)
{
	char	*str;
	size_t	size;
	size_t	i;

	str = (char *)s;
	size = 0;
	while (*str != c && *str && ++size)
		str++;
	str = malloc(size + 1);
	if (!str)
		return (0);
	i = -1;
	while (++i < size)
		str[i] = *s++;
	str[i] = 0;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	size_t	j;
	size_t	size;
	char	**strr;

	if (!s)
		return (0);
	size = ft_cmp(s, c);
	strr = malloc(sizeof(char *) * (size + 1));
	if (!strr)
		return (0);
	j = -1;
	while (++j < size)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			strr[j] = ft_cpy(s, c);
			if (!strr[j])
				return (0);
			s += ft_strlen(strr[j]);
		}
	}
	strr[size] = 0;
	return (strr);
}
