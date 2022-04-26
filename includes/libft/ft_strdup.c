/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:37:24 by ataverni          #+#    #+#             */
/*   Updated: 2021/03/31 19:42:56 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (src[i])
	{	
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
