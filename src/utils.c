/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:01:12 by ataverni          #+#    #+#             */
/*   Updated: 2022/03/21 16:05:31 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	ft_strlen_2d(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			;
	}
	else
		return (0);
	return (i);
}

int	ft_strlen_cub(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int	ft_is_troll_str(char *file)
{
	int	i;

	i = -1;
	if (file)
	{
		while (file[++i] && (file[i] == 32 || file[i] == '\t'))
			;
		if (!file[i] || file[i] == '\n')
			return (1);
		else
			return (0);
	}
	return (0);
}

int	ft_isonly_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
			i++;
		if (!str[i])
			break ;
		if (str[i] && str[i] == '1')
		{
			while (str[i] && str[i] == '1')
				i++;
			if (!str[i])
				break ;
		}
		if (str[i] == '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_first_and_lastchar(char *str)
{
	int	i;
	int	passage;

	i = -1;
	passage = 0;
	while (str[++i])
	{
		if (str[i] == '1' && passage == 0)
		{
			while (str[i] && (str[i] == '1' || str[i] == '0'))
				i++;
			if (str[i] != '1')
				return (0);
			passage++;
		}
		else
			i++;
		if (!str)
			break ;
	}
	return (1);
}

char	**ft_copy_tab(char **map, int indexstart, int indexlast)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * (indexlast - indexstart) + 1);
	if (!new)
		return (NULL);
	while (map[i] && i != indexstart)
		i++;
	while (map[i] && i != indexlast)
		new[j++] = ft_strdup(map[i++]);
	new[j] = NULL;
	return (new);
}
