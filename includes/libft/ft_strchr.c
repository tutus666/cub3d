/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:32:58 by ataverni          #+#    #+#             */
/*   Updated: 2021/03/31 19:35:28 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int find)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str);
	while (i != (j + 1))
	{		
		if (str[i] == (char)find)
			return ((char *)str + i);
		i++;
	}
	if (!str && !find)
		return ((char *)str);
	else
		return (NULL);
}
