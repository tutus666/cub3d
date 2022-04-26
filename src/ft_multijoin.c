/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multijoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:50:33 by ataverni          #+#    #+#             */
/*   Updated: 2022/03/21 15:56:53 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

char	*ft_strjoin_space(char *str, int max)
{
	int		i;
	char	*new;

	printf("ton input %s\n", str);
	new = malloc(max + 1);
	if (!new)
		return (NULL);
	i = -1;
	if (str)
	{
		while (str[++i])
			new[i] = str[i];
		ft_free(str);
	}
	else
		i = 0;
	while (i < max)
		new[i++] = 32;
	printf("ton i %d & ton max %d \n", i, max);
	if (i == max)
		new[i] = 0;
	printf("ton new %s\n", new);
	return (new);
}

char	*ft_minijoint_size(char *src, char dst, int size)
{
	char	*new;
	int		i;

	new = malloc(size + 1);
	i = -1;
	if (src)
	{
		while (src[++i])
			new[i] = src[i];
		ft_free(src);
	}
	else
		i = 0;
	new[i] = dst;
	while (i < size)
		new[i++] = 32;
	new[i] = 0;
	return (new);
}

char	*ft_strjoinfree(char *src, char *dst)
{
	int		i;
	int		j;
	char	*new;

	new = malloc(ft_strlen_cub(dst) + ft_strlen_cub(src) + 2);
	if (!new)
		return (NULL);
	i = -1;
	if (dst)
	{
		while (dst[++i])
			new[i] = dst[i];
		ft_free(dst);
	}
	else
		i = 0;
	j = -1;
	if (src)
	{
		while (src[++j])
			new[i + j] = src[j];
		ft_free(src);
	}
	else
	j = 0;
	new[i + j] = '\n';
	new[i + j + 1] = 0;
	return (new);
}

char	*ft_strjoin_cub(char *src, char *dst)
{
	int		i;
	int		j;
	char	*new;

	new = malloc(ft_strlen_cub(dst) + ft_strlen_cub(src) + 2);
	if (!new)
		return (NULL);
	i = -1;
	if (src)
	{
		while (src[++i])
			new[i] = src[i];
		ft_free(src);
	}
	else
		i = 0;
	j = -1;
	if (dst)
	{
		while (dst[++j])
			new[i + j] = dst[j];
	}
	else
		j = 0;
	new[i + j] = '\n';
	new[i + j + 1] = 0;
	return (new);
}

char	*ft_strjoinwithchar(char *str, char *tmp, char c, char *new)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	new = malloc(ft_strlen_cub(str) + ft_strlen_cub(tmp) + 2);
	if (!new)
		return (NULL);
	if (tmp)
	{
		while (tmp[++i])
			new[i] = tmp[i];
		ft_free(tmp);
	}
	else
		i = 0;
	if (str)
	{
		while (str[++j])
			new[i + j] = tmp[i];
	}
	else
		j = 0;
	new[i + j] = c;
	new[i + j + 1] = 0;
	return (new);
}
