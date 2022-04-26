/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:05:36 by ataverni          #+#    #+#             */
/*   Updated: 2022/03/21 16:07:19 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			printf("tab : |%s|\n", tab[i]);
	}	
}

void	ft_print_map(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			printf("tab : |%s| && ton strlen %d && ton i %d\n", tab[i], ft_strlen_map(tab[i]), i);
	}
}

int	ft_strlen_map(char *str)
{
	int	i;
	int	cmpt;

	cmpt = 0;
	i = -1;
	if (str)
	{
		while (str[++i])
		{
			if (str[i] == '\t')
				cmpt += 4;
			else
				cmpt++;
		}
	}
	return (cmpt);
}

char	*ft_leavefirstspace(char *str)
{
	int		i;
	int		size;
	char	*new;

	size = 0;
	i = 0;
	new = NULL;
	if (str)
	{
		while (str[i] && (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r')))
			i++;
		while (str[i + size])
			size++;
		new = malloc(size + 1);
		if (!new)
			return (NULL);
		size = 0;
		while (str[i])
			new[size++] = str[i++];
		new[size] = 0;
	}
	return (new);
}

int	ft_isonlyspace(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && ((str[i] < '\t' || str[i] > '\r')))
			return (0);
	}
	return (1);
}
